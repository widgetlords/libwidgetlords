from ctypes import *
from enum import Enum
from time import sleep

import os

pi_spi_din = cdll.LoadLibrary('libwidgetlords.so')

def pi_spi_din_init():
    pi_spi_din.pi_spi_din_init()
    
class ChipEnable(Enum):
    CE0 = 0
    CE1 = 1
    CE2 = 2
    CE3 = 3
    CE4 = 4

class Mod4KO:
    def __init__(self, chip_enable: ChipEnable, address: int = 0):
        self.chip_enable = chip_enable.value
        self.address = address
        pi_spi_din.pi_spi_din_4ko_init(self.chip_enable, self.address)

    def write(self, state: int):
        pi_spi_din.pi_spi_din_4ko_write(self.chip_enable, self.address, state)

    def write_single(self, channel: int, state: int):
        pi_spi_din.pi_spi_din_4ko_write_single(self.chip_enable, self.address, channel, state)

class Mod8DI:
    def __init__(self, chip_enable: ChipEnable, address: int = 0):
        self.chip_enable = chip_enable.value
        self.address = address
        pi_spi_din.pi_spi_din_8di_init(self.chip_enable, self.address)

    def read(self):
        return pi_spi_din.pi_spi_din_8di_read(self.chip_enable, self.address)

    def read_single(self, channel: int):
        return pi_spi_din.pi_spi_din_8di_read_single(self.chip_enable, self.address, channel)

class Mod8AI:
    def __init__(self, chip_enable: ChipEnable):
        self.chip_enable = chip_enable.value

    def read_single(self, channel: int):
        return pi_spi_din.pi_spi_din_8ai_read_single(self.chip_enable, channel)

class Mod4AO:
    def __init__(self):
        pi_spi_din.pi_spi_din_4ao_init()

    def write_single(self, channel: int, counts: int):
        pi_spi_din.pi_spi_din_4ao_write_single(channel, counts)
        
class SDAFEType(Enum):
    TYPE_1_MA = 1		# Input 0 to 20 mA, Returns 0 to 20000, Scaler 1000
    TYPE_2_MA = 2		# Input 0 to 20 mA, Returns 0 to 10000, Scaler 100
    TYPE_3_MA = 3 	# Input 4 to 20 mA, Returns 0 to 10000, Scaler 100 Note: Readings below 4 mA return as 0

    TYPE_4_5VDC = 4 # Input 0 to 5 VDC, Returns 0 to 5000, Scaler 1000
    TYPE_5_5VDC = 5	# Input 0 to 5 VDC, Returns 0 to 10000, Scaler 100
    TYPE_6_5VDC = 6	# Input 1 to 5 VDC, Returns 0 to 10000, Scaler 100 Note: Readngs beluw 1 VDC return as 0

    TYPE_7_10VDC = 7	# Input 0 to 10 VDC, Returns 0 to 10000, Scaler 1000
    TYPE_8_10VDC = 8	# Input 0 to 10 VDC, Returns 0 to 10000, Scaler 100
    TYPE_9_10VDC = 9	# Input 2 to 10 VDC, Returns 0 to 10000, Scaler 100 Note: Readings below 2 VDC return as 0	TYPE_1_MA = 1
    
class SDAFEStatus(Enum):
    OK = 0
    POLARITY = 1
    OVER_RANGE = 2
    COMM_ERROR = 3
    
class sdafe_reading(Structure):
    _fields_ = [
        ('value', c_ushort),
        ('status', c_int),
        ('counts', c_ushort),
        ('type', c_int)
    ]
pi_spi_din.sdafe_read.restype = sdafe_reading

class SDAFEReading:
    def __init__(self, reading: sdafe_reading):
        #print(reading.value, reading.status, reading.counts, reading.type)
        self.status = SDAFEStatus(reading.status)
        self.value = reading.value
        self.counts = reading.counts
        self.type = SDAFEType(reading.type)
        
class SDAFE:
    def __init__(self, channel: int):
        self.channel = channel
        
    def set_type(self, type: SDAFEType):
        pi_spi_din.sdafe_set_type(self.channel, type)
        
    def read(self):
        return SDAFEReading(pi_spi_din.sdafe_read(self.channel))
        
class VPE2901A:
    def __init__(self):
        pi_spi_din.vpe_2901a_init()
        self.sdafe1 = SDAFE(6)
        self.sdafe2 = SDAFE(7)
        
    def ao_write_single(self, channel: int, counts: int):
        pi_spi_din.vpe_2901a_2ao_write_single(channel, counts)
    
    def ko_write_single(self, channel: int, value: int):
        pi_spi_din.vpe_2901a_2ko_write_single(channel, value)
        
    def di_read_single(self, channel: int):
        return pi_spi_din.vpe_2901a_2di_read_single(channel)
    
class VPE3011B:
    def __init__(self):
        pi_spi_din.vpe_3011b_init()
        self.sdafe1 = SDAFE(6)
        self.sdafe2 = SDAFE(7)
        self.sdafe3 = SDAFE(8)
        self.sdafe4 = SDAFE(9)
    
    def ko_write_single(self, channel: int, value: int):
        pi_spi_din.vpe_3011b_4ko_write_single(channel, value)
        
    def di_read_single(self, channel: int):
        return pi_spi_din.vpe_3011b_8di_read_single(channel)
    
    def di_read(self):
        return pi_spi_din.vpe_3011b_8di_read()