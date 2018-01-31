from ctypes import cdll
from enum import Enum
from time import sleep

import os

#__location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
#libPath = os.path.join(__location__, 'libpi_spi_din.so')
#pi_spi_din = cdll.LoadLibrary(libPath)
pi_spi_din = cdll.LoadLibrary('libpi_spi_din.so')

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