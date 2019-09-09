from time import sleep
from widgetlords.pi_spi import *

outputs = Mod2AO()
while True:
    outputs.write_single(0, 745)
    outputs.write_single(1, 3723)
    sleep(2)
    
    outputs.write_single(0, 3733)
    outputs.write_single(1, 745)
    sleep(2)