##
## square.py
## sample code to control a Mindstorm EV3 to move in a square path
##

from ev3 import *

rub = Robot()

rub.mot_mid = Motor('A')
rub.mot_left = Motor('B')
rub.mot_right = Motor('C')

rub.mot_right.rotate_forever(200)
rub.mot_left.rotate_forever(200)
time.sleep(2.0)

rub.mot_left.stop()
time.sleep(2.0)

rub.mot_left.rotate_forever(200)
time.sleep(2.0)

rub.mot_left.stop()
time.sleep(2.0)

rub.mot_left.rotate_forever(200)
time.sleep(2.0)

rub.mot_left.stop()
time.sleep(2.0)

rub.mot_left.rotate_forever(200)
time.sleep(2.0)

rub.mot_left.stop()
rub.mot_right.stop()
rub.mot_mid.stop()
