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

typedef enum opcion_recursiva{
    FALSE, TRUE
} opc;

//Enum de estados de espacio en el mall
typedef enum Disponibilidad{
    DESOCUPADO, OCUPADO
} dis;

typedef enum edit_field{
    NOMBRE = 1, UBICACION = 2
} campo; //El id no es modificable por el usuario

//Mostrar un local especifico
void mostrarLocal(local_t ** centroComercial, dis **availability, short piso,
    short espacio_piso);

//Funcion que devulve las dimensiones especificadas del mall
void determinarDimensionesMall(short dimensiones_mall[]);

//Guarda la direccion verificada del local dada por el usuario 
void determinarDireccionLocal(short direccion_local[], short dimensiones_mall[]);

//Crea el espacio del nuevo mall
local_t **construirCentroComercial(short dimensiones_mall[]);

//Crea el arreglo que verifica la disponibilidad
dis **alocarEspacioMatrizDisponibilidad(short dimensiones_mall[]);

//Verificacion de espacio en ubicacion determinada por usuario}
dis verificarUbicacionLocal(dis **Mall_availability, short piso, short espacio_piso);

//Se llenan campos importantes de la informacion del mall
void establecerNuevoLocal(local_t ** pMatriz , short direccion_local[]);

//Administrar la disponibilidad en el arreglo del mismo nombre
void establecerDisponibilidad(dis **Mall_availability, dis Disponibilidad, 
    short direccion_local[]); 

//Funcion revursiva que da cuenta del espacio disponible
/*Recibe como parametro Verdadero o Falso si se desea el espacio para todo el edificio
 o solo para una fila concreta*/
short reportarEspacioDisponible(dis **availability,  short dimensiones_mall[], 
    short piso, opc busqueda_completa);

//Muestra la informacion de un conjunto de locales
/*Si se le da como parametro verdadero, muestra todos los locales 
del centro comercial. Si se deja como falso, solo muestra los locales del 
piso especificado*/
void mostrarInformacionLocales(local_t **centroComercial, dis **availability, short piso, short dimensiones_mall[], 
    opc busqueda_piso_completa);


/*Permite editar la informacion de un local a la vez
Se localiza el local de interes de acuerdo a su direccion. Para esto el
usuario debe hacer uso de mostrar informacion de local para todo el centro y obtener
su ubicacion*/
void editarInfoLocal(local_t **centroComercial, dis **availability, short piso, short espacio_piso,
    short dimensiones_mall[]);

#endif /* FUNCIONESCC_H_ */