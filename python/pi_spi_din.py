from ctypes import cdll
from enum import Enum
from time import sleep

import os

__location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
libPath = os.path.join(__location__, 'libpi_spi_din.so')
pi_spi_din = cdll.LoadLibrary(libPath)

def pi_spi_din_init():
    pi_spi_din.pi_spi_din_init()
    
class ChipSelect(Enum):
    CE0 = 8
    CE1 = 7
    CE2 = 24
    CE3 = 23
    CE4 = 18

class Mod4KO:
    def __init__(self, chip_select: ChipSelect, address: int = 0):
        self.chip_select = chip_select.value
        self.address = address
        pi_spi_din.pi_spi_din_4ko_init(self.chip_select, self.address)

    def write(self, state: int):
        pi_spi_din.pi_spi_din_4ko_write(self.chip_select, self.address, state)

    def write_single(self, channel: int, state: int):
        pi_spi_din.pi_spi_din_4ko_write_single(self.chip_select, self.address, channel, state)

class Mod8DI:
    def __init__(self, chip_select: ChipSelect, address: int = 0):
        self.chip_select = chip_select.value
        self.address = address
        pi_spi_din.pi_spi_din_8di_init(self.chip_select, self.address)

    def read(self):
        return pi_spi_din.pi_spi_din_8di_read(self.chip_select, self.address)

    def read_single(self, channel: int):
        return pi_spi_din.pi_spi_din_8di_read_single(self.chip_select, self.address, channel)

class Mod8AI:
    def __init__(self, chip_select: ChipSelect):
        self.chip_select = chip_select.value

    def read_single(self, channel: int):
        return pi_spi_din.pi_spi_din_8ai_read_single(self.chip_select, channel)

class Mod4AO:
    def __init__(self):
        pi_spi_din.pi_spi_din_4ao_init()

    def write_single(self, channel: int, counts: int):
        pi_spi_din.pi_spi_din_4ao_write_single(channel, counts)