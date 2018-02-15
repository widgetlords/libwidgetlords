#!/bin/sh

dtc -@ -I dts -O dtb -o pi-spi-din.dtbo pi-spi-din.dts
dtc -@ -I dts -O dtb -o pi-spi-din-mio.dtbo pi-spi-din-mio.dts
#install *.dtbo /boot/overlays