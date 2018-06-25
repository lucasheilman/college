##
## sample.py
## sample code to control a Mindstorm EV3 using Python
##

from ev3dev.ev3 import *

# intialize the motors our robot will use
#motor_mid = LargeMotor('outA') #This is currently made up
motor_left = LargeMotor('outB')
motor_right = LargeMotor('outC')

# initialize the color sensor connected to port 3
color_sensor = ColorSensor('in2')

# make the EV# ouput the specified text
Sound.speak("Ready to go!")

# rotate the left and right motors for 3 seconds
motor_left.run_forever(speed_sp=200)
motor_right.run_forever(speed_sp=200)
time.sleep(3)

# while our color sensor detects light terrain
color_sensor.mode='COL-REFLECT'

while color_sensor.value() > 15:
    time.sleep(0)

# rotate left motor slower for 1 second, then faster for 2 seconds
# the right motor is still moving
motor_left.run_forever(speed_sp=100)
time.sleep(1.0)
motor_left.run_forever(speed_sp=200)
time.sleep(2.0)

# while our color sensors detect medium terrain
while color_sensor.value() > 50:
    time.sleep(0)

# power down the motors
time.sleep(0.5)
motor_left.stop(stop_action='brake')
motor_right.stop(stop_action='brake')
time.sleep(0.5)
#motor_mid.rotate_position(0.5, 150)

Sound.speak('Power down.')

time.sleep(1.0)

# rotate the left motor backward for 4.2 seconds
motor_left.run_forever(speed_sp=-200)
time.sleep(4.2)

# go forward for 3 seconds
motor_left.run_forever(speed_sp=300)
motor_right.run_forever(speed_sp=300)
time.sleep(3)

# command will not run since sleep is not called
motor_left.run_forever(speed_sp=200)
motor_right.run_forever(speed_sp=200)


while color_sensor.value() > 15:
    time.sleep(0)

# rotate the right motor for .25 seconds
motor_right.run_forever(speed_sp=450)
time.sleep(.25)

# stop all motors
motor_right.stop(stop_action='brake')
motor_left.stop(stop_action='brake')
#motor_mid.stop(stop_action='brake')
