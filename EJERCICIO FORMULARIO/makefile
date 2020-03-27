all: programa

programa: main formulario
	gcc -o exe main.o formulario.o

main: main.c formulario.h
	gcc -c main.c 

formulario: formulario.c formulario.h
	gcc -c formulario.c