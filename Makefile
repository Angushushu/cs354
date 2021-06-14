main: main.o func.o
	gcc main.o func.o -o main
main.o: main.c
	gcc -c main.c
func.o: func.h func.c
	gcc -c func.c
