test: dir
	gcc -I src -o build/test src/test/main.c

dir:
	[ -d build ] || mkdir build
