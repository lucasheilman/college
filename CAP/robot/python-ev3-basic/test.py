from ev3 import *

rub = Robot()

rub.mot_a = Motor('A')

print rub.mot_a.get_position()	# prints out the position of the motor
rub.mot_a.rotate_position(100) 	# rotates the motor forward 100 units
rub.mot_a.goto_position(50)		# rotates the motor to position 50
rub.mot_a.wait_for_stop()		# waits until the motor is done moving to move on to the next command
print rub.mot_a.get_position()

rub.mot_A.rotate_forever(200)   # rotates the motor at speed 200 until told to stop
time.sleep(2)                   # doesn't move to the next command command until after 2 seconds has past
rub.talk("stopping the motor")  # makes the robot say "stopping the motor"
rub.mot_A.stop()                # stops the motor

rub.leds = Leds()

rub.leds.set_led_red_right(1)	# turns the right LED red
rub.leds.set_led_green_left(1)	# turns the left LED green

rub.touch_sensor()

while not rub.touch_sensor.is_pushed():		# while the touch sensor is not pushed
    if rub.touch_sensor.is_pushed():        # if the touch sensor is pushed
        rub.talk("pushed")                  # makes the robot say "pushed"

rub.color_sensor = Color_sensor()

print rub.color_sensor.get_reflect()		# print the numerical value of the color sensors input
