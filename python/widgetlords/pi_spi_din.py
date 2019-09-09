from ctypes import *
from enum import Enum
from . import widgetlords

__all__ = []

def init():
    widgetlords.pi_spi_din_init()
__all__.append('init')
    
class ChipEnable(Enum):
    CE0 = 0
    CE1 = 1
    CE2 = 2
    CE3 = 3
    CE4 = 4
__all__.append('ChipEnable')

class Mod4KO:
    def __init__(self, chip_enable: ChipEnable, address: int = 0):
        self.chip_enable = chip_enable.value
        self.address = address
        widgetlords.pi_spi_din_4ko_init(self.chip_enable, self.address)

    def write(self, state: int):
        widgetlords.pi_spi_din_4ko_write(self.chip_enable, self.address, state)

    def write_single(self, channel: int, state: int):
        widgetlords.pi_spi_din_4ko_write_single(self.chip_enable, self.address, channel, state)
__all__.append('Mod4KO')

class Mod8DI:
    def __init__(self, chip_enable: ChipEnable, address: int = 0):
        self.chip_enable = chip_enable.value
        self.address = address
        widgetlords.pi_spi_din_8di_init(self.chip_enable, self.address)

    def read(self):
        return widgetlords.pi_spi_din_8di_read(self.chip_enable, self.address)

    def read_single(self, channel: int):
        return widgetlords.pi_spi_din_8di_read_single(self.chip_enable, self.address, channel)
__all__.append('Mod8DI')

class Mod8AI:
    def __init__(self, chip_enable: ChipEnable):
        self.chip_enable = chip_enable.value

    def read_single(self, channel: int):
        return widgetlords.pi_spi_din_8ai_read_single(self.chip_enable, channel)
__all__.append('Mod8AI')

class Mod4AO:
    def __init__(self, address: int = 0):
        self.address = address

    def write_single(self, channel: int, counts: int):
        widgetlords.pi_spi_din_4ao_write_single(self.address, channel, counts)
__all__.append('Mod4AO')

class Mod4Freq:
    def __init__(self, chip_enable: ChipEnable, address: int = 0):
        self.chip_enable = chip_enable.value
        self.address = address

    def read_fixed(self, channel: int):
        return widgetlords.pi_spi_din_4freq_read_fixed(self.chip_enable, self.address, channel)

    def read_variable(self, channel: int):
        return widgetlords.pi_spi_din_4freq_read_variable(self.chip_enable, self.address, channel)

    def read_pulse(self, channel: int):
        return widgetlords.pi_spi_din_4freq_read_pulse(self.chip_enable, self.address, channel)

    def read_di(self):
        return widgetlords.pi_spi_din_4freq_read_di(self.chip_enable, self.address)
__all__.append('Mod4Freq')
        
class SDAFEType(Enum):
    TYPE_1_MA = 1		# Input 0 to 20 mA, Returns 0 to 20000, Scaler 1000
    TYPE_2_MA = 2		# Input 0 to 20 mA, Returns 0 to 10000, Scaler 100
    TYPE_3_MA = 3 	    # Input 4 to 20 mA, Returns 0 to 10000, Scaler 100 Note: Readings below 4 mA return as 0

    TYPE_4_5VDC = 4     # Input 0 to 5 VDC, Returns 0 to 5000, Scaler 1000
    TYPE_5_5VDC = 5	    # Input 0 to 5 VDC, Returns 0 to 10000, Scaler 100
    TYPE_6_5VDC = 6	    # Input 1 to 5 VDC, Returns 0 to 10000, Scaler 100 Note: Readngs beluw 1 VDC return as 0

    TYPE_7_10VDC = 7	# Input 0 to 10 VDC, Returns 0 to 10000, Scaler 1000
    TYPE_8_10VDC = 8	# Input 0 to 10 VDC, Returns 0 to 10000, Scaler 100
    TYPE_9_10VDC = 9	# Input 2 to 10 VDC, Returns 0 to 10000, Scaler 100 Note: Readings below 2 VDC return as 0	TYPE_1_MA = 1
__all__.append('SDAFEType')
    
class SDAFEStatus(Enum):
    OK = 0
    POLARITY = 1
    OVER_RANGE = 2
    COMM_ERROR = 3
__all__.append('SDAFEStatus')
    
class sdafe_reading(Structure):
    _fields_ = [
        ('value', c_ushort),
        ('status', c_int),
        ('counts', c_ushort),
        ('type', c_int)
    ]
widgetlords.sdafe_read.restype = sdafe_reading

class SDAFEReading:
    def __init__(self, reading: sdafe_reading):
        #print(reading.value, reading.status, reading.counts, reading.type)
        self.status = SDAFEStatus(reading.status)
        self.value = reading.value
        self.counts = reading.counts
        self.type = SDAFEType(reading.type)
__all__.append('SDAFEReading')
        
class SDAFE:
    def __init__(self, channel: int):
        self.channel = channel
        
    def set_type(self, type: SDAFEType):
        widgetlords.sdafe_set_type(self.channel, type)
        
    def read(self):
        return SDAFEReading(widgetlords.sdafe_read(self.channel))
__all__.append('SDAFE')
        
class VPE2901A:
    def __init__(self):
        widgetlords.vpe_2901a_init()
        self.sdafe1 = SDAFE(6)
        self.sdafe2 = SDAFE(7)
        
    def ao_write_single(self, channel: int, counts: int):
        widgetlords.vpe_2901a_2ao_write_single(channel, counts)
    
    def ko_write_single(self, channel: int, value: int):
        widgetlords.vpe_2901a_2ko_write_single(channel, value)
        
    def di_read_single(self, channel: int):
        return widgetlords.vpe_2901a_2di_read_single(channel)
__all__.append('VPE2901A')
    
class VPE3011B:
    def __init__(self):
        widgetlords.vpe_3011b_init()
        self.sdafe1 = SDAFE(6)
        self.sdafe2 = SDAFE(7)
        self.sdafe3 = SDAFE(8)
        self.sdafe4 = SDAFE(9)
    
    def ko_write_single(self, channel: int, value: int):
        widgetlords.vpe_3011b_4ko_write_single(channel, value)
        
    def di_read_single(self, channel: int):
        return widgetlords.vpe_3011b_8di_read_single(channel)
    
    def di_read(self):
        return widgetlords.vpe_3011b_8di_read()
__all__.append('VPE3011B')