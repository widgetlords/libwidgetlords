all:
	meson bin --prefix /usr/
	cd bin; ninja

install:
	cd bin; ninja install

clean:
	rm -rf bin