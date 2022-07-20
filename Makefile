dir:
	[ -d build ] || mkdir build

compile_test: dir
	gcc -I src -o build/test test/test.c

test: compile_test
	build/test.exe
