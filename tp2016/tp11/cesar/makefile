CFLAGS=-g -Wall -Wconversion
main.exe: main.o functions.o
	gcc main.o functions.o -o main.exe
main.o: main.c header.h
	gcc $(CFLAGS) -c main.c
functions.o: functions.c header.h
	gcc $(CFLAGS) -c functions.c
clean:
	rm *.o *.exe *.gch
