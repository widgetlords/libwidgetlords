all:
	meson setup build
	meson configure --buildtype release --prefix /usr -D python=true build
	cd build; ninja

install:
	cd build; meson install
