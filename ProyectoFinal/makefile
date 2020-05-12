all:programa

programa: main FuncionesCC
	g++ -o mallAdmin main.o FuncionesCC.o

main: main.cpp FuncionesCC.h
	g++ -c main.cpp

FuncionesCC: FuncionesCC.cpp FuncionesCC.h
	g++ -c FuncionesCC.cpp