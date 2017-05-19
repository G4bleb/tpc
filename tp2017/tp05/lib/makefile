#lib statique dans le répertoire local
truc.exe: main.o libf.a
	gcc main.o libf.a -o truc.exe
libf.a: f1.o f2.o
	ar rv libf.a f1.o f2.o
main.o: main.c f.h
	gcc -c main.c
f1.o: f1.c f.h
	gcc -c f1.c
f2.o: f2.c f.h
	gcc -c f2.c
clean:
	rm *.o *.exe
