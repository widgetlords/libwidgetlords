from time import sleep
from widgetlords.pi_spi import *

inputs = Mod8AI()
while True:
    for i in range(8):
        print(inputs.read_single(i))
        sleep(0.5)