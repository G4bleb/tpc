CFLAGS=-g -Wall -Wconversion
main.exe: main.o functions.o
	gcc main.o functions.o -o main.exe -lm
main.o: main.c header.h
	gcc $(CFLAGS) -c main.c -lm
functions.o: functions.c header.h
	gcc $(CFLAGS) -c functions.c -lm
clean:
	rm *.o *.exe *.gch
