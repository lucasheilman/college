#!/usr/bin/env python3
from ev3dev.ev3 import *
from time import sleep
motor_left=LargeMotor('outB')
motor_right=LargeMotor('outC')

motor_left.run_forever(speed_sp=150)
motor_right.run_forever(speed_sp=150)
sleep(2.0)
motor_left.stop(stop_action='brake')
Leds.set_color(Leds.LEFT, Leds.RED)
Leds.set_color(Leds.RIGHT, Leds.GREEN)
sleep(3.0)
motor_left.run_forever(speed_sp=150)
sleep(2.0)
motor_left.stop(stop_action='brake')
motor_right.stop(stop_action='brake')

Sound.speak('Hi my name is Bob').wait()


Leds.set_color(Leds.RIGHT, Leds.RED)
Leds.set_color(Leds.LEFT, Leds.GREEN)

