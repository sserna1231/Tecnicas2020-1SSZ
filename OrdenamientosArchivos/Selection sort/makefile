programa: select
select: main selection
	gcc -o select main.o selection.o
selection: selection.c selection.h
	gcc -c selection.c
main: main.c selection.h
	gcc -c main.c
