CFLAGS=-g -Wall -Wconversion
main.exe: main.o grid.o robot.o graph.o
	gcc main.o grid.o robot.o graph.o -lSDL -o main.exe
main.o: main.c header.h
	gcc $(CFLAGS) -c main.c
grid.o: grid.c header.h
	gcc $(CFLAGS) -c grid.c
robot.o: robot.c header.h
	gcc $(CFLAGS) -c robot.c
graph.o: graph.c header.h
		gcc $(CFLAGS) -c graph.c
clean:
	rm *.o *.exe
