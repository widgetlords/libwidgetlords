from time import sleep
from widgetlords.pi_spi import *

init()

inputs = Mod8AI()
while True:
    print(inputs.read_single(0))
    sleep(0.5)