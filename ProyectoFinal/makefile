all:programa

programa: main FuncionesCC
	g++ -o mallAdmin main.o FuncionesCC.o

main: main.c FuncionesCC.h
	g++ -c main.c

FuncionesCC: FuncionesCC.c FuncionesCC.h
	g++ -c FuncionesCC.c