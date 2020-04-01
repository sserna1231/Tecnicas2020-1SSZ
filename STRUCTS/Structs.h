/* Esto se incluye para evitar inclusion repetida de informacion*/
#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <stdio.h>
#include <stdlib.h>

struct Fish {
	char nombre[25];
	char especie[20];
	int numDientes;
	int edad;
};

//EL typedef es un "alias" para decir struct Fish
typedef struct Fish fish_t;

/*El siguiente struct es equivalente al anterior, simplemente
que cambia el uso del keyword typedef. Aquí se usa en la misma 
declaración*/
typedef struct Fish2 {
	char nombre[25];
	char especie[20];
	int numDientes;
	int edad;
}fish_t2;


struct Fish llenarFishMemEstatica();

/*Con typedef*/
fish_t llenarFishTypeDef();

//Note que se manda fish t pq es equivalente a decir struct fish
void imprimirDatosPasoValor(fish_t fish);

// Imprime los datos datos de un struct de tipo fish enviando los parámetros 
// por referecia
void imprimirDatosPasoReferencia(fish_t * fish);

struct Fish * llenarFishMemDinamica();

/*Este siguiente prototipo sobra*/
void imprimirDatosPasoReferencia(struct Fish * pFish);

#endif