#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Persona{

    char name[30];
    short dia, mes, year;
} user;

typedef enum months{
    ENERO = 1, FEBRERO = 2, MARZO = 3, ABRIL = 4, MAYO = 5, 
    JUNIO = 6, JULIO = 7, AGOSTO = 8, SEPTIEMBRE = 9, OCTUBRE = 10, 
    NOVIEMBRE = 11, DICIEMBRE =12
} mes;

enum options{
    SALIR, LOG_IN, SHOW_INFO, RECURSION
};

void llenarForm(user* usuario_nuevo);

void imprimirDatosUsuario(user nuevo);

void verificarMesUsuario(user* usuario);

void guardarNuevoUsuario(user Matriz[][5], user* nuevo_registro_usuario);

//Devuelve la cantidad de segundos desde una fecha dada hasta ahora
double segundosActualidad();

/*Funcion de Lucas. De preferencia que sea un booleano*/


