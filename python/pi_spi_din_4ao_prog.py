#!/usr/bin/python3

import RPi.GPIO as GPIO

from subprocess import call
from sys import exit
from time import sleep

DELAY = 0.005

SCK = 3
SDA = 2

try:
    old_address = int(input('Old address: '))
    new_address = int(input('New address: '))
    if old_address > 7 or old_address < 0 or new_address > 7 or new_address < 0:
        raise
except:
    print('Invalid address')
    print('Address must be between 0 and 7')
    exit(1)

#if old_address > 0x67 or old_address < 0x60 or new_address > 0x67 or new_address < 0x60:
#    print('Invalid address')
#    print('Address must be between 0x60 and 0x67')
#    exit(1)

GPIO.setmode(GPIO.BCM)  # Use RPi GPIO numbers
GPIO.setwarnings(False) # disable warnings

GPIO.setup(SCK, GPIO.OUT)
GPIO.setup(SDA, GPIO.OUT)
GPIO.output(SCK, 1)
GPIO.output(SDA, 1)

def i2c_ack_byte():
    GPIO.setup(SDA, GPIO.IN)
    GPIO.output(SCK, 1)
    sleep(DELAY)
    GPIO.output(SCK, 0)
    GPIO.setup(SDA, GPIO.OUT)

def i2c_write_byte(byte):
    for i in range(8):
        sleep(DELAY)
        GPIO.output(SCK, 0)
        
        if byte & 0x80:
            GPIO.output(SDA, 1)
        else:
            GPIO.output(SDA, 0)
            
        sleep(DELAY)
        GPIO.output(SCK, 1)
        
        byte <<= 1
        
    sleep(DELAY)
    GPIO.output(SCK, 0)
    GPIO.output(SDA, 0)
    
    
data = [
    (old_address + 0x60) << 1,
    0x61 | (old_address << 2),
    0x62 | (new_address << 2),
    0x63 | (new_address << 2)
]
	
GPIO.output(SDA, 0)
sleep(DELAY)

i2c_write_byte(data[0])
i2c_ack_byte()

i2c_write_byte(data[1])
input('Insert jumper J1 and press enter')
i2c_ack_byte()

i2c_write_byte(data[2])
i2c_ack_byte()

i2c_write_byte(data[3])
i2c_ack_byte()

GPIO.output(SDA, 0)

sleep(DELAY)
GPIO.output(SCK, 1)

GPIO.output(SDA, 1)

GPIO.cleanup()
print('Attempting to reset I2C bus...')
call(['modprobe', '-r', 'i2c_bcm2835'])
call(['modprobe', 'i2c_bcm2835'])

print('Done! Remove the jumper')