CC=g++
CFLAGS=-Wall -W -fmax-errors=1

main.exe: common_defs.h list-copy.o pile.o file.o fileprior.o  main_LQS.cpp
	$(CC) $(CFLAGS) list-copy.o pile.o file.o fileprior.o main_LQS.cpp -o main.exe

list-copy.o: list-copy.h list-copy.cpp
	$(CC) $(CFLAGS) -c list-copy.cpp

pile.o: pile.h pile.cpp list-copy.h
	$(CC) $(CFLAGS) -c pile.cpp

file.o: file.h pile.h file.h
	$(CC) $(CFLAGS) -c file.cpp

fileprior.o: fileprior.h fileprior.cpp file.h
	$(CC) $(CFLAGS) -c fileprior.cpp

stack_composition.o: stack_composition.h  stack_composition.h
	$(CC) $(CFLAGS) -c stack_composition.h
