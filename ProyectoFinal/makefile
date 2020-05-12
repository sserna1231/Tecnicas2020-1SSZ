all:programa

programa: main FuncionesCC
	gcc -o exe main.o FuncionesCC.o

main: main.c FuncionesCC.h
	gcc -c main.c

FuncionesCC: FuncionesCC.c FuncionesCC.h
	gcc -c FuncionesCC.c