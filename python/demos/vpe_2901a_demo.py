#!/bin/python

from time import sleep
from widgetlords.pi_spi_din import *

vpe = VPE2901A()
while True:
    vpe.ko_write_single(0, 1)
    vpe.ko_write_single(1, 0)
    vpe.ao_write_single(0, 2700)
    vpe.ao_write_single(1, 0)
    di1 = vpe.di_read_single(0)
    di2 = vpe.di_read_single(1)
    print("DI:", di1, di2, "\n")
		
    an1 = vpe.sdafe1.read()
    an2 = vpe.sdafe2.read()
    print("SDAFE: ", an1.status, an1.value, "\t", an2.status, an2.value, "\n")
    
    sleep(1)
    
    vpe.ko_write_single(0, 0)
    vpe.ko_write_single(1, 1)
    vpe.ao_write_single(0, 0)
    vpe.ao_write_single(1, 2700)
    di1 = vpe.di_read_single(0)
    di2 = vpe.di_read_single(1)
    print("DI:", di1, di2, "\n")
		
    an1 = vpe.sdafe1.read()
    an2 = vpe.sdafe2.read()
    print("SDAFE: ", an1.status, an1.value, "\t", an2.status, an2.value, "\n")
    
    sleep(1)

