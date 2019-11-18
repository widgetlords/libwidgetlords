from . import widgetlords

__all__ = []

def init():
    widgetlords.pi_spi_init()
__all__.append('init')

class Mod8KO:
    def __init__(self, optional: bool = False):
        self.optional = optional

    def write(self, data):
        widgetlords.pi_spi_8ko_write(data, int(self.optional))

    def write_single(self, channel: int, data: int):
        widgetlords.pi_spi_8ko_write_single(channel, data, int(self.optional))
__all__.append('Mod8KO')

class Mod8DI:
    def __init__(self, address: int = 0, optional: bool = False):
        self.address = address
        self.optional = optional
        widgetlords.pi_spi_8di_init(self.address, int(self.optional))

    def read(self):
        return widgetlords.pi_spi_8di_read(self.address, int(self.optional))

    def read_single(self, channel: int):
        return widgetlords.pi_spi_8di_read_single(self.address, channel, int(self.optional))
__all__.append('Mod8DI')

class Mod8AI:
    def __init__(self, spare: int = 0):
        self.spare = int(spare) % 4

    def read_single(self, channel: int):
        return widgetlords.pi_spi_8ai_read_single(channel, self.spare)
__all__.append('Mod8AI')

class Mod2AO:
    def __init__(self, optional: bool = False):
        self.optional = optional

    def write_single(self, channel: int, counts: int):
        widgetlords.pi_spi_2ao_write_single(channel, counts, int(self.optional))
__all__.append('Mod2AO')

class Mod8AI16B:
    def __init__(self, spare: int = 0):
        self.spare = int(spare) % 4

    def set_channel(self, channel: int):
        widgetlords.pi_spi_8ai_16b_set_channel(channel)

    def read(self):
        return widgetlords.pi_spi_8ai_16b_read(self.spare)
__all__.append('Mod8AI16B')
