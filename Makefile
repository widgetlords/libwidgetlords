all:
	meson bin --prefix /usr/
	cd bin; mesonconf -D python=true
	cd bin; ninja

install:
	cd bin; ninja install
	cd overlays; sh overlay.sh

clean:
	rm -rf bin
	rm -f overlays/*.dtbo
