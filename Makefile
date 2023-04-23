test: dir
	gcc -I"src" -o debug/test src/test/main.c

dir:
	[ -d debug ] || mkdir debug
