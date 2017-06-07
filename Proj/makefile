CFLAGS=-g -Wall -Wconversion
main.exe: main.o functions.o robot.o graph.o
	gcc main.o functions.o robot.o graph.o -lSDL -o main.exe
main.o: main.c header.h
	gcc $(CFLAGS) -c main.c
functions.o: functions.c header.h
	gcc $(CFLAGS) -c functions.c
robot.o: robot.c header.h
	gcc $(CFLAGS) -c robot.c
graph.o: graph.c header.h
		gcc $(CFLAGS) -c graph.c
clean:
	rm *.o *.exe
