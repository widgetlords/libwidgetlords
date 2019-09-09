#!/bin/python

from time import sleep
from widgetlords.pi_spi_din import *

vpe = VPE3011B()
while True:
    vpe.ko_write_single(0, 1)
    vpe.ko_write_single(1, 1)
    vpe.ko_write_single(2, 0)
    vpe.ko_write_single(3, 0)
    di = vpe.di_read()
    print("DI:", di, "\n")
		
    an1 = vpe.sdafe1.read()
    an2 = vpe.sdafe2.read()
    an3 = vpe.sdafe3.read()
    an4 = vpe.sdafe4.read()
    print("SDAFE: ", an1.status, an1.value, "\t", an2.status, an2.value, "\n")
    print("SDAFE: ", an3.status, an3.value, "\t", an4.status, an4.value, "\n")
    
    sleep(1)
    
    vpe.ko_write_single(0, 0)
    vpe.ko_write_single(1, 0)
    vpe.ko_write_single(2, 1)
    vpe.ko_write_single(3, 1)
    di = vpe.di_read()
    print("DI:", di, "\n")
		
    an1 = vpe.sdafe1.read()
    an2 = vpe.sdafe2.read()
    an3 = vpe.sdafe3.read()
    an4 = vpe.sdafe4.read()
    print("SDAFE: ", an1.status, an1.value, "\t", an2.status, an2.value, "\n")
    print("SDAFE: ", an3.status, an3.value, "\t", an4.status, an4.value, "\n")
    
    sleep(1)