CC=g++
CFLAGS=-Wall -W -fmax-errors=1

main.exe: common_defs.h MVector.o Matrix.o SquareMatrix.o DiagonalMatrix.o ScalarMatrix.o main_squarematrix.cpp
	$(CC) $(CFLAGS) MVector.o Matrix.o SquareMatrix.o DiagonalMatrix.o ScalarMatrix.o main_squarematrix.cpp -o main.exe

MVector.o: MVector.h MVector.cpp
	$(CC) $(CFLAGS) -c MVector.cpp

Matrix.o: MVector.h Matrix.h Matrix.cpp
	$(CC) $(CFLAGS) -c Matrix.cpp

SquareMatrix.o: Matrix.h SquareMatrix.h SquareMatrix.cpp
	$(CC) $(CFLAGS) -c SquareMatrix.cpp

DiagonalMatrix.o: SquareMatrix.h DiagonalMatrix.h DiagonalMatrix.cpp
	$(CC) $(CFLAGS) -c DiagonalMatrix.cpp

ScalarMatrix.o: DiagonalMatrix.h ScalarMatrix.h ScalarMatrix.cpp
	$(CC) $(CFLAGS) -c ScalarMatrix.cpp