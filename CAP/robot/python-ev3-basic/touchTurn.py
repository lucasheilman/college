from ev3 import *

rub = Robot()

rub.mot_mid = Motor("A")
rub.mot_left=Motor("B")
rub.mot_right=Motor("C")

rub.touch_sensor = Touch_sensor()


rub.mot_left.rotate_forever(400)
rub.mot_right.rotate_forever(400)

while not rub.touch_sensor.is_pushed():
    time.sleep(0)

rub.talk("i am a robot")
rub.mot_left.rotate_forever(200)
rub.mot_right.rotate_forever(-300)
time.sleep(1.3)


rub.mot_left.rotate_forever(400)
rub.mot_right.rotate_forever(400)
time.sleep(1.0)
rub.mot_left.stop()
rub.mot_right.stop()
rub.mot_mid.stop()
