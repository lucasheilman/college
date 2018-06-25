""" The main module that interfaces with the EV3 hardware.

Provides a variety of classes to interface with the EV3 in
an object-oriented manner.
"""

# import pyudev
import time
from subprocess import Popen
import os
import math

class Communicate(object):
    @staticmethod
    def read(path):
        with open(path, 'r') as pin:
            return pin.read().strip()

    @staticmethod
    def write(path, value):
        with open(path, 'w') as pout:
            pout.write(value)

    @staticmethod
    def min_max(value, mini=-100, maxi=100):
        return max(mini, min(maxi, value))


class Sensor(Communicate):
    mode = 'no_mode'
    def __init__(self, type_id=None, port=None):
        if port and port not in ('1', '2', '3', '4'):
            raise ValueError('Sensor Port is not valid')

        for sensor in pyudev.Context().list_devices(subsystem='msensor'):
            if type_id:
                if type_id == int(sensor.get('TYPEID')):
                    self.path = sensor.sys_path
                    break
            if port:
                if 'in' +  port == sensor.get('PORT', ''):
                    self.path = sensor.sys_path
                    break

        else:  # I love for-else blocks
            raise EnvironmentError("Sensor not found")

    def set_mode(self, mode):
        if self.mode != mode:
            self.mode = mode
            self.write(self.path + '/mode', mode)
            time.sleep(0.1)

    def get_values(self, nb_val):
        values = []
        for i in range(nb_val):
            values.append(int(self.read(self.path + '/value' + str(i))))

        return values

    def get_value(self):
        return self.get_values(1)[0]


class Touch_sensor(Sensor):
    def __init__(self):
        Sensor.__init__(self, type_id=16)

    def is_pushed(self):
        return self.get_value()


class Color_sensor(Sensor):
    colors = (None, 'black', 'blue', 'green', 'yellow', 'red', 'white', 'brown')

    def __init__(self):
        Sensor.__init__(self, type_id=29)

    def get_rgb(self):
        self.set_mode('RGB-RAW')
        return self.get_values(3)

    def get_reflect(self):
        self.set_mode('COL-REFLECT')
        return self.get_value()

    def get_ambient(self):
        self.set_mode('COL-AMBIENT')
        return self.get_value()

    def get_color(self):
        self.set_mode('COL-COLOR')
        return self.colors[self.get_value()]


class Infrared_sensor(Sensor):
    def __init__(self):
        Sensor.__init__(self, type_id=33)

    def get_remote(self):
        self.set_mode('IR-REMOTE')
        return self.get_values(4)

    def get_remote_bin(self):
        self.set_mode('IR-REM-A')
        return self.get_value()

    def get_prox(self):
        self.set_mode('IR-PROX')
        return self.get_value()

    def get_seek(self):
        self.set_mode('IR-SEEK')
        h1, p1, h2, p2, h3, p3, h4, p4 = self.get_values(8)
        seeks = [(1, h1, p1), (2, h2, p2), (3, h3, p3), (4, h4, p4)]
        channels = {}
        for id, h, p in seeks:
            if p != 128:
                if h > 128:
                    h = h - 256
                channels[id] = (h, p)

        return channels


class Motor(Communicate):
    def __init__(self, port):
        if port.upper() not in ('A', 'B', 'C', 'D'):
            raise ValueError('Motor Port is not valid')

        for device in pyudev.Context().list_devices(subsystem='tacho-motor'):
            if 'out' + port.upper() == device.get('PORT', ''):
                self.path = device.sys_path + '/'
                break

        else:
            raise EnvironmentError("Motor not found")

    def set_run_mode(self, value):
        path = self.path + 'run_mode'
        self.write(path, value)
        while self.get_run_mode() != value:
            time.sleep(0.05)

    def set_stop_mode(self, value):
        path = self.path + 'stop_mode'
        self.write(path, value)
        while self.get_stop_mode() != value:
            time.sleep(0.05)

    def set_regulation_mode(self, value):
        path = self.path + 'regulation_mode'
        self.write(path, value)
        while self.get_regulation_mode() != value:
            time.sleep(0.05)

    def set_position_mode(self, value):
        path = self.path + 'position_mode'
        self.write(path, value)
        while self.get_position_mode() != value:
            time.sleep(0.05)

    def get_run_mode(self):
        return self.read(self.path + 'run_mode')

    def get_stop_mode(self):
        return self.read(self.path + 'stop_mode')

    def get_regulation_mode(self):
        return self.read(self.path + 'regulation_mode')

    def get_position_mode(self):
        return self.read(self.path + 'position_mode')

    # ___ sp ___
    
    def set_duty_cycle_sp(self, value):
        path = self.path + 'duty_cycle_sp'
        self.write(path, str(value))

    def set_pulses_per_second_sp(self, value):
        path = self.path + 'pulses_per_second_sp'
        self.write(path, str(value))

    def set_time_sp(self, value):
        path = self.path + 'time_sp'
        self.write(path, str(value))

    def set_position_sp(self, value):
        path = self.path + 'position_sp'
        self.write(path, str(value))

    def get_duty_cycle_sp(self):
        return int(self.read(self.path + 'duty_cycle_sp'))

    def get_pulses_per_second_sp(self):
        return int(self.read(self.path + 'pulses_per_second_sp'))

    def get_time_sp(self):
        return int(self.read(self.path + 'time_sp'))

    def get_position(self):
        return int(self.read(self.path + 'position'))

    # ___ info ___
    
    def reset_position(self, value = 0):
        path = self.path + 'position'
        self.write(path, str(value))

    def get_duty_cycle(self):
        return int(self.read(self.path + 'duty_cycle'))

    def get_position(self):
        return int(self.read(self.path + 'position'))

    def get_power(self):
        return int(self.read(self.path + 'power'))

    def get_state(self):
        return self.read(self.path + 'state')

    # ___ macros ___

    def set_ramps(self, up, down):
        path = self.path + 'ramp_up_sp'
        self.write(path, str(up))
        path = self.path + 'ramp_down_sp'
        self.write(path, str(down))

    def rotate_forever(self, speed=480, regulate='on', stop_mode='brake'):
        self.set_run_mode('forever')
        self.set_stop_mode(stop_mode)
        if regulate=='on':
            self.set_pulses_per_second_sp(speed)
        else:
            self.set_duty_cycle_sp(speed)
        self.set_regulation_mode(regulate)
        self.run()

    def rotate_time(self, time, speed=480, up=0, down=0, regulate='on', stop_mode='brake'):
        self.set_run_mode('time')
        self.set_stop_mode(stop_mode)
        self.set_regulation_mode(regulate)
        self.set_ramps(up, down)
        if regulate=='on':
            self.set_pulses_per_second_sp(speed)
        else:
            self.set_duty_cycle_sp(speed)
        self.set_time_sp(time)
        self.run()

    def rotate_position(self, position, speed=480, up=0, down=0, regulate='on', stop_mode='brake'):
        self.set_run_mode('position')
        self.set_position_mode('relative')
        self.set_stop_mode(stop_mode)
        self.set_regulation_mode(regulate)
        self.set_ramps(up, down)
        if regulate=='on':
            self.set_pulses_per_second_sp(speed)
        else:
            self.set_duty_cycle_sp(speed)
        self.set_position_sp(position)
        self.run()

    def goto_position(self, position, speed=480, up=0, down=0, regulate='on', stop_mode='brake', wait=0):
        self.set_run_mode('position')
        self.set_position_mode('absolute')
        self.set_stop_mode(stop_mode)
        self.set_regulation_mode(regulate)
        self.set_ramps(up, down)
        if regulate=='on':
            self.set_pulses_per_second_sp(speed)
        else:
            self.set_duty_cycle_sp(speed)
        self.set_position_sp(position)
        sign = math.copysign(1, self.get_position() - position)
        self.run()
        if (wait):
            new_pos = self.get_position()
            nb_same = 0
            while (sign * (new_pos - position) > 5):
                time.sleep(0.05)
                old_pos = new_pos
                new_pos = self.get_position()
                if old_pos == new_pos:
                    nb_same += 1
                else:
                    nb_same = 0
                if nb_same > 10:
                    break
            time.sleep(0.05)
            if (not stop_mode == "hold"):
                self.stop()

    def wait_for_stop(self):
        time.sleep(0.1)
        while abs(self.get_duty_cycle()) > 3:
            time.sleep(0.05)

    def run(self, value=1):
        path = self.path + 'run'
        self.write(path, str(value))

    def stop(self, stop_mode='coast'):
        self.run(0)
        self.set_stop_mode(stop_mode)


class LCD(Communicate):
    """Structure representing and LCD screen.
    
    Attribuites:
        LCD_path: Path for the LCD on the EV3, set to /dev/fb0.
    """
    def __init__(self):
        self.LCD_path = '/dev/fb0'

    def clear_screen(self):
        """Clears the screen.
        
        /dev/zero displays as many nullbytes as are read from it, while
        /dev/fb0 is the screen's framebuffer. We call cat to insert
        numerous nullbytes into the framebuffer, which clears it.
        """
        os.system('cat /dev/zero > /dev/fb0')


class Leds(Communicate):
    """Structure representing an LED.
    
    Attributes:
        path: Path for the LEDs on the EV3, set to /sys/class/leds.
    """
    def __init__(self):
        self.path = '/sys/class/leds/'

    def set_led(self, color, led, value):
        """Sets the color, intensity, and specifies the specific LED to set.
        
        Args:
            color: Integer value of either 0 (red) or 1 (green).
            led: Integer value of either 0 (left) or 1 (right).
            value: Integer value that indicates the brightness of the LED.
        """
        color_text = ['red', 'green']
        led_text = ['left', 'right']
        path = self.path + 'ev3:' + color_text[color] + ':' + led_text[led]
        self.write(path + '/brightness', str(value))

    def set_led_red_left(self, value):
        """Sets the red LED on the left side of the EV3 brick."""
        self.set_led(0, 0, value)

    def set_led_red_right(self, value):
        """Sets the red LED on the right side of the EV3 brick."""
        self.set_led(0, 1, value)

    def set_led_green_left(self, value):
        """Sets the green LED on the left side of the EV3 brick."""
        self.set_led(1, 0, value)

    def set_led_green_right(self, value):
        """Sets the green LED on the right side of the EV3 brick."""
        self.set_led(1, 1, value)

    def get_led(self, color, led):
        """Gets the value of a specific LED on the EV3 brick.
        
        Args:
            color: Integer value of either 0 (red) or 1 (green).
            led: Integer value of either 0 (left) or 1 (right).
        
        Returns:
            An integer specifying the path of the LED.
        """
        color_text = ['red', 'green']
        led_text = ['left', 'right']
        path = self.path + 'ev3:' + color_text[color] + ':' + led_text[led]
        return int(self.read(path + '/brightness'))

    def get_led_red_left(self):
        """Returns the red LED on the left side of the EV3 brick."""
        return self.get_led(0, 0)

    def get_led_red_right(self):
        """Returns the red LED on the right side of the EV3 brick."""
        return self.get_led(0, 1)

    def get_led_green_left(self):
        """Returns the green LED on the left side of the EV3 brick."""
        return self.get_led(1, 0)

    def get_led_green_right(self):
        """Returns the green LED on the right side of the EV3 brick."""
        return self.get_led(1, 1)


class Robot(Communicate):
    """Represents the physical EV3 brick.
        
    The Robot class handles calls that execute a given command in a subshell.
    os.system() calls provide most of the functionality for the Robot class.
        
    Attributes:
        leds: An instance of the LED class for the LEDs on the EV3 controls.
        LCD: An instance of the LCD class that controls the EV3 LCD screen.
    """
    def __init__(self):
        self.leds = Leds()
        self.LCD = LCD()

    def beep(self):
        """Executes the beep command in a subshell."""
        self.write('/sys/devices/platform/snd-legoev3/volume', '100')
        os.system('beep')

    def talk(self, s, wait=1):
        """The EV3 brick outputs the specified string through the speaker.
            
        Args:
            s: The string that should be converted to speech.
            wait: Default value of 1.
        """
        self.write('/sys/devices/platform/snd-legoev3/volume', '100')
        if wait:
            os.system('espeak -v en -p 20 -s 120 "' + s + '" --stdout | aplay')
        else:
            espeak = Popen(("espeak","-v","en","-p","20","-s","120",'"' + s + '"',"--stdout"), stdout=PIPE)
            output = check_output(('aplay'), stdin=espeak.stdout)

    def show_image(self, path):
        """Shows an image on the EV3 LCD from the specified path."""
        os.system('fbi -d /dev/fb0 -T 1 -noverbose -a ' + path)

