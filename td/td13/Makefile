
CC=g++
CFLAGS=-Wall -W -fmax-errors=1

main_movable.exe: main_movable.o
	${CC} ${CFLAGS} 2_main_movable.cpp -o main_movable.exe

	
main_movable.o: movable.hpp 2_main_movable.cpp
	${CC} ${CFLAGS} -c 2_main_movable.cpp


main_copiable.exe: main_copiable.o
	${CC} ${CFLAGS} 1_main_copiable.o -o main_copiable.exe

	
main_copiable.o: copiable.hpp 1_main_copiable.cpp
	${CC} ${CFLAGS} -c 1_main_copiable.cpp 


main_unique.exe: main_unique.o
	${CC} ${CFLAGS} 4_main_uniqueptr.cpp -o main_unique.exe

	
main_unique.o: uniqueptr.hpp 4_main_uniqueptr.cpp
	${CC} ${CFLAGS} -c 4_main_uniqueptr.cpp 


main_ptr.exe: main_ptr.o
	${CC} ${CFLAGS} 3_main_ptr.cpp -o main_ptr.exe

	
main_ptr.o: movable.hpp 3_main_ptr.cpp
	${CC} ${CFLAGS} -c 3_main_ptr.cpp 