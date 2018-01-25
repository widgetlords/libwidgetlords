from ctypes import cdll
from time import sleep

import os

__location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
libPath = os.path.join(__location__, 'bin/libpi_spi.so')
pi_spi = cdll.LoadLibrary(libPath)

def pi_spi_init():
    pi_spi.pi_spi_init()

class Mod8KO:
    def __init__(self, optional: bool = False):
        self.optional = optional

    def write(self, data):
        pi_spi.pi_spi_8ko_write(data, int(self.optional))

    def write_single(self, data: int, channel: int):
        pi_spi.pi_spi_8ko_write_single(data, channel, int(self.optional))

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

    def write_single(self, counts: int, channel: int):
        pi_spi.pi_spi_2ao_write_single(counts, channel, int(self.optional))

pi_spi_init()

'''relays = Mod8KO()
while True:
    #relays.write(0x00)
    relays.write_single(0, 0)
    sleep(1)
    #relays.write(0xFF)
    relays.write_single(1, 0)
    sleep(1)'''

'''inputs = Mod8DI()
while True:
    print(inputs.read())
    sleep(0.5)'''

'''inputs = Mod8AI()
while True:
    print(inputs.read_single(1))
    sleep(0.5)'''

outputs = Mod2AO()
while True:
    outputs.write_single(745, 0)
    outputs.write_single(3723, 1)
    sleep(2)
    
    outputs.write_single(3733, 0)
    outputs.write_single(745, 1)
    sleep(2)
