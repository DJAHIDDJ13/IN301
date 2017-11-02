all: circMorph
	./circMorph

circMorph: circMorph.c
	gcc -g -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT "circMorph.c" -o "circMorph" -luvsqgraphics -L/usr/lib/i386-linux-gnu -lSDL -lm -lSDL_ttf

clean:
	rm -f circMorph
