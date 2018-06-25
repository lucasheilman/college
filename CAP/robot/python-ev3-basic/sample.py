##
## sample.py
## sample code to control a Mindstorm EV3 using Python
##

from ev3 import *

# create a Robot object to control the robot
rub = Robot()

# intialize the motors our robot will use
rub.mot_mid = Motor('A')
rub.mot_left = Motor('B')
rub.mot_right = Motor('C')

# initialize the color sensor connected to port 3
rub.color_sensor = Color_sensor()

# make the EV3 output the specified text
rub.talk("Ready to go!")

# rotate the left and right motors for 3 seconds
rub.mot_left.rotate_forever(200)
rub.mot_right.rotate_forever(200)
time.sleep(3)

# while our color sensor detects light terrain
while rub.color_sensor.get_reflect() > 15:
     time.sleep(0)

# rotate left motor slower for 1 second, then faster for 2 seconds
# the right motor is still moving
rub.mot_left.rotate_forever(100)
time.sleep(1.0)
rub.mot_left.rotate_forever(200)
time.sleep(2.0)

# while our color sensors detect medium terrain
while rub.color_sensor.get_reflect() > 50:
     time.sleep(0)

# power down the motors
time.sleep(0.5)
rub.mot_left.stop()
rub.mot_right.stop()
time.sleep(0.5)
rub.mot_mid.rotate_position(0.5, 150)
rub.talk("Power down.")

time.sleep(1.0)

# rotate the left motor backward for 4.2 seconds
rub.mot_left.rotate_forever(-200)
time.sleep(4.1)

# go forward for 3 seconds
rub.mot_left.rotate_forever(300)
rub.mot_right.rotate_forever(300)
time.sleep(3)

# command will not run since sleep is not called
rub.mot_left.rotate_forever(200)
rub.mot_right.rotate_forever(200)

while rub.color_sensor.get_reflect() > 15:
     time.sleep(0)

# rotate the right motor for .25 seconds
rub.mot_right.rotate_forever(450)
time.sleep(.25)

# stop all motors
rub.mot_left.stop()
rub.mot_right.stop()
rub.mot_mid.stop()

