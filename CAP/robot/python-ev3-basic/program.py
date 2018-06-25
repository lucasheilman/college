from ev3 import *
import pyudev

rub=Robot()
rub.mot_left=Motor('B')
rub.mot_right=Motor('C')
rub.leds=Leds()

rub.mot_left.rotate_forever(150)
rub.mot_right.rotate_forever(150)
time.sleep(2.0)
rub.mot_left.stop()
rub.leds.set_led_red_left(1)
rub.leds.set_led_red_right(0)
rub.leds.set_led_green_right(1)
time.sleep(3.0)
rub.mot_left.rotate_forever(150)
time.sleep(2.0)
rub.mot_right.stop()
rub.mot_left.stop()

rub.talk("That's what she said")

rub.leds.set_led_green_right(0)
rub.leds.set_led_red_left(0)
rub.leds.set_led_red_right(1)
rub.leds.set_led_green_left(1)
rub.leds.set_led_red_right(0)
rub.leds.set_led_green_left(0)
