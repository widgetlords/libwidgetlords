from time import sleep
from widgetlords.pi_spi_din import *

outputs = Mod4AO()
while True:
    outputs.write_single(0, 745)
    outputs.write_single(2, 745)
    outputs.write_single(1, 3723)
    outputs.write_single(3, 3723)
    sleep(2)
    
    outputs.write_single(0, 3733)
    outputs.write_single(2, 3733)
    outputs.write_single(1, 745)
    outputs.write_single(3, 745)
    sleep(2)