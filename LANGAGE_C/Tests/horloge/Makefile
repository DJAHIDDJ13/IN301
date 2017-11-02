all: horloge
	./horloge

horloge: horloge.c
	gcc -g -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT "horloge.c" -o "horloge" -luvsqgraphics -L/usr/lib/i386-linux-gnu -lSDL -lm -lSDL_ttf

clean:
	rm -f horloge
