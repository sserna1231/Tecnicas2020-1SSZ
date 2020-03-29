#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIA_SEC 86400
#define MONTH_SEC 2592000 //En promedio
#define YEAR_SEC 31104000 //En promedio
#define DEFAULT_PERSONA_STRUCT {"", 0, 0, 0}

typedef struct Persona{

    char name[30];
    short dia, mes, year;
} user;

typedef enum months{
    ENERO = 1, FEBRERO = 2, MARZO = 3, ABRIL = 4, MAYO = 5, 
    JUNIO = 6, JULIO = 7, AGOSTO = 8, SEPTIEMBRE = 9, OCTUBRE = 10, 
    NOVIEMBRE = 11, DICIEMBRE =12
} mes;

enum time_scala{
    YEAR = 1, MONTH = 2, DAY = 3
};

enum options{
    SALIR, LOG_IN, SHOW_INFO, RECURSION
};

void llenarForm(user* usuario_nuevo);

void imprimirDatosUsuario(user usuario_nuevo);

void verificarMesUsuario(user* usuario);

void guardarNuevoUsuario(user Matriz[][5], user* nuevo_registro_usuario);

//Devuelve la cantidad de segundos desde una fecha dada hasta ahora
double segundosActualidad();

int verificarEspacio(user Matriz[][5], short mes);

void mostrarDatosMes(user Matriz[][5], short mes);

double segundosActualidad(enum time_scala time, int birth_year_user);


