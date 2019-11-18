from time import sleep
from widgetlords.pi_spi import *

inputs = Mod8AI16B()
while True:
    for i in range(8):
        inputs.set_channel(i)
        print(inputs.read())
        sleep(0.5)
