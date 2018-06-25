##
## square.py
## sample code to control a Mindstorm EV3 to move in a square path
##

from ev3dev.ev3 import *

#motor_mid = LargeMotor('outA')
motor_left = LargeMotor('outB')
motor_right = LargeMotor('outC')

motor_right.run_forever(speed_sp=200)
motor_left.run_forever(speed_sp=200)
time.sleep(2.0)

motor_left.stop(stop_action='brake')
time.sleep(2.0)

motor_left.run_forever(speed_sp=200)
time.sleep(2.0)

motor_left.stop(stop_action='brake')
time.sleep(2.0)

motor_left.run_forever(speed_sp=200)
time.sleep(2.0)

motor_left.stop(stop_action='brake')
time.sleep(2.0)

motor_left.run_forever(speed_sp=200)
time.sleep(2.0)


motor_left.stop(stop_action='brake')
motor_right.stop(stop_action='brake')
#motor_mid.stop(stop_action='brake')