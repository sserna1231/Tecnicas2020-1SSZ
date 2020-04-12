#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Local 
typedef struct Local{
    char nombreLocal[35];
    int idLocal; // Calculado automaticamente por su programa
    int pisoLocal;
    int numLocalxPiso;//Columnas
    // Completelo con lo que quiera
} local_t;

//Enum de estados de espacio en el mall
typedef enum Disponibilidad{
    DESOCUPADO, OCUPADO
} dis;

//Funcion que devulve las dimensiones especificadas del mall
void determinarDimensionesMall(short dimensiones_mall[]);

//Guarda la direccion verificada del local dada por el usuario 
void determinarDireccionLocal(short direccion_local[], short dimensiones_mall[]);

/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(local_t ** centroComercial, int numPiso,
        int numLocalxPiso, int numPisos, int numLocalesxPiso);

//Crea el espacio del nuevo mall
local_t **construirCentroComercial(short dimensiones_mall[]);

//Crea el arreglo que verifica la disponibilidad
dis **alocarEspacioMatrizDisponibilidad(short dimensiones_mall[]);

//Verificacion de espacio en ubicacion determinada por usuario}
short verificarUbicacionLocal(dis **Mall_availability, short direccion_local[]);

//Se llenan campos importantes de la informacion del mall
void establecerNuevoLocal(local_t ** pMatriz , short direccion_local[]);

//Administrar la disponibilidad en el arreglo del mismo nombre
void establecerDisponibilidad(dis **Mall_availability, dis Disponibilidad, 
    short direccion_local[]); 

#endif /* FUNCIONESCC_H_ */