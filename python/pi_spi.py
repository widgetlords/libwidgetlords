from ctypes import cdll
from time import sleep

import os

#__location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
#libPath = os.path.join(__location__, 'libpi_spi.so')
#pi_spi = cdll.LoadLibrary(libPath)
pi_spi = cdll.LoadLibrary('libwidgetlords.so')

def pi_spi_init():
    pi_spi.pi_spi_init()

class Mod8KO:
    def __init__(self, optional: bool = False):
        self.optional = optional

    def write(self, data):
        pi_spi.pi_spi_8ko_write(data, int(self.optional))

    def write_single(self, channel: int, data: int):
        pi_spi.pi_spi_8ko_write_single(channel, data, int(self.optional))

class Mod8DI:
    def __init__(self, address: int = 0, optional: bool = False):
        self.address = address
        self.optional = optional
        pi_spi.pi_spi_8di_init(self.address, int(self.optional))

    def read(self):
        return pi_spi.pi_spi_8di_read(self.address, int(self.optional))

    def read_single(self, channel: int):
        return pi_spi.pi_spi_8di_read_single(channel, self.address, int(self.optional))

class Mod8AI:
    def __init__(self, optional: bool = False):
        self.optional = optional

    def read_single(self, channel: int):
        return pi_spi.pi_spi_8ai_read_single(channel, int(self.optional))

class Mod2AO:
    def __init__(self, optional: bool = False):
        self.optional = optional

    def write_single(self, channel: int, counts: int):
        pi_spi.pi_spi_2ao_write_single(channel, counts, int(self.optional))