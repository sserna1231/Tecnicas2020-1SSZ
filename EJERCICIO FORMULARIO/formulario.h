#include <stdio.h>
#include <stdlib.h>

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

/*Procedimiento de Lucas. De preferencia que sea un booleano*/


