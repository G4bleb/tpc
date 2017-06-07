CFLAGS=-g -Wall -Wconversion
main.exe: main.o functions.o robot.o
	gcc main.o functions.o robot.o -o main.exe
main.o: main.c header.h
	gcc $(CFLAGS) -c main.c
functions.o: functions.c header.h
	gcc $(CFLAGS) -c functions.c
robot.o: robot.c header.h
	gcc $(CFLAGS) -c robot.c
clean:
	rm *.o *.exe
