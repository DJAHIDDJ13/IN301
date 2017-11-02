all: cube
	./cube

cube: cube.c
	gcc -g -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT "cube.c" -o "cube" -luvsqgraphics -L/usr/lib/i386-linux-gnu -lSDL -lm -lSDL_ttf

clean:
	rm -f cube
