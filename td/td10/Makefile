CC=g++
CFLAGS=-Wall -W -fmax-errors=1

main.exe: common_defs.h expr-abstract.h expr-concrete.h ternary.h variable.h  main_expr-ext.cpp
	$(CC) $(CFLAGS) expr-abstract.h expr-concrete.h ternary.h variable.h main_expr-ext.cpp -o main.exe


expr-concrete.o: expr-concrete.h  expr-concrete.cpp
	$(CC) $(CFLAGS) -c expr-concrete.cpp

ternary.o: ternary.h ternary.cpp
	$(CC) $(CFLAGS) -c ternary.cpp

variable.o: variable.h variable.cpp
	$(CC) $(CFLAGS) -c variable.cpp

