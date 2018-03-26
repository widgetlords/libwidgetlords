from time import sleep
from widgetlords.pi_spi import *

init()

inputs = Mod8DI()
while True:
    print(inputs.read())
    sleep(0.5)