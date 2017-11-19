principal: principal.o circonference.o surface.o
	gcc -g circonference.o principal.o surface.o -lm -o principal

exe: principal
	./principal $(R)

circonference.o: circonference.c pi.h circonference.h
	gcc -g -c circonference.c -o circonference.o -lm

surface.o: surface.c pi.h surface.h 
	gcc -g -c surface.c -o surface.o

principal.o: principal.c surface.c surface.h circonference.c circonference.h
	gcc -g -c principal.c -o principal.o -lm

clean:
	rm -f principal principal.o surface.o circonference.o
