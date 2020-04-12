#include "FuncionesCC.h"

/* Funcion de ejemplo que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial){
    
    short direccion_local[2];

    determinarDireccionLocal(direccion_local);
    
    printf("\n\n=========================\nNombre: %s\n", 
        centroComercial[direccion_local[0]][direccion_local[1]].nombreLocal);
    printf("Piso: %d Espacio en piso: %d\n", 
        centroComercial[direccion_local[0]][direccion_local[1]].pisoLocal, 
        centroComercial[direccion_local[0]][direccion_local[1]].numLocalxPiso);
    printf("ID: %i\n\n", centroComercial[direccion_local[0]][direccion_local[1]].idLocal);
}

void determinarDimensionesMall(short dimensiones_mall[]){

    short pisos, locales_piso;

    do{
        printf("Digite el numero de pisos del mall:\n> ");
        scanf("%hd", &pisos);
            if(pisos < 1) 
                printf("Valor invalido\n\n");
    }while(pisos < 1);

    do{
        printf("Digite el numero de espacios para locales por piso del mall:\n> ");
        scanf("%hd", &locales_piso);
            if(locales_piso < 1) 
                printf("Valor invalido\n\n");
    }while(locales_piso < 1);

    dimensiones_mall[0] = pisos;
    dimensiones_mall[1] = locales_piso; 
}

//Determina la direccion del nuevo local
void determinarDireccionLocal(short direccion_local[], short dimensiones_mall[]){

    short piso, lugar_piso;

    do{
        printf("Digite el piso del local:\n> ");
        scanf("%hd", &piso);
            if(piso < 1 || piso > dimensiones_mall[0]) 
                printf("Valor invalido\n\n");
    }while(piso < 1 || piso > dimensiones_mall[0]);

    do{
        printf("Digite el espacio del local en el piso establecido:\n> ");
        scanf("%hd", &lugar_piso);
            if(lugar_piso < 1 || lugar_piso > dimensiones_mall[1]) 
                printf("Valor invalido\n\n");
    }while(lugar_piso < 1 || lugar_piso > dimensiones_mall[1]);

    direccion_local[0] = piso;
    direccion_local[1] = lugar_piso; 
}

//Se crea el arreglo dinamico que representa el Mall
local_t **construirCentroComercial(short dimensiones_mall[]){

    int i, j;
    local_t **pMall = malloc(dimensiones_mall[0] * sizeof(local_t*));

    if(pMall != NULL){
        for(i = 0; i < dimensiones_mall[0]; i++){
          pMall[i] = malloc(dimensiones_mall[1] * sizeof(local_t));
        }
    } else{
    printf("Error reservando la memoria\n");
    }
    return pMall;
}

//Matriz de disponibilidad
 dis **alocarEspacioMatrizDisponibilidad(short dimensiones_mall[]){

    dis disponibilidad;
    int i, j;
    dis **pDisponibilidad = malloc(dimensiones_mall[0] * sizeof(dis*));

    if(pDisponibilidad != NULL){
        for(i = 0; i < dimensiones_mall[0]; i++){
          pDisponibilidad[i] = malloc(dimensiones_mall[1] * sizeof(dis));
        }
    } else{
    printf("Error reservando la memoria\n");
    }

    //Inicializando
    for(i = 0; i < dimensiones_mall[0]; i++){
        for(j = 0; j < dimensiones_mall[1]; j++){
            pDisponibilidad[i][j] = DESOCUPADO;
        }
    }
    return pDisponibilidad;
}

//Verificacion de espacio en ubicacion determinada por usuario}
short verificarUbicacionLocal(dis **Mall_availability, short piso, short espacio_piso){

    short piso, espacio_piso;
    dis disponibilidad_espacio;

    piso = direccion_local[0];
    espacio_piso = direccion_local[1];
    if(!Mall_availability[piso - 1][espacio_piso - 1]) return DESOCUPADO;
    else return OCUPADO;
}

//Se llenan campos importantes de la informacion del mall
void establecerNuevoLocal(local_t ** pMatriz , short direccion_local[]){

    local_t new_local;

    //Establecer el nombre del lugar
    printf("Introduzca el nombre del establecimiento:\n> ");
    fflush(stdin);
    fgets(new_local.nombreLocal, 35, stdin);
    //Quitar el caracter de salto de linea
    for(int k = 0; k < 35; k++){
        if(new_local.nombreLocal[k] == '\n')
            new_local.nombreLocal[k] = '\0';
    }
    
    //Establecer la direccion del local
    new_local.pisoLocal = direccion_local[0];
    new_local.numLocalxPiso = direccion_local[1];

    //Generar ID
    new_local.idLocal = rand() + direccion_local[0] + direccion_local[1];

    //Registrarlo dentro del arreglo dinamico
    pMatriz[direccion_local[0] - 1][direccion_local[1] - 1] = new_local;
}

//Administrar la disponibilidad en el arreglo del mismo nombre
void establecerDisponibilidad(dis **Mall_availability, dis Disponibilidad, 
    short direccion_local[]){

    switch(Disponibilidad){
        case DESOCUPADO:
            Mall_availability[direccion_local[0] - 1][direccion_local[1] - 1] = 0;
            break;
        case OCUPADO:
            Mall_availability[direccion_local[0] - 1][direccion_local[1] - 1] = 1;
            break;
        default: printf("Opcion de disponibilidad desconocida");
    }
}

//Funcion revursiva que da cuenta del espacio disponible
/*Recibe como parametro Verdadero o Falso si se desea el espacio para todo el edificio
 o solo para una fila concreta*/
short reportarEspacioDisponible(short **disponibilidad,  short dimensiones_mall[], 
    short piso, opc busqueda_completa){

    short i = dimensiones_mall[0] - 1;
    short j = dimensiones_mall[1] - 1;

    switch(busqueda_completa){
        case FALSE:
            if(j = 0) return verificarUbicacionLocal(disponibilidad, piso, 0);
            else{
                return verificarUbicacionLocal(disponibilidad, piso, j) + 
                    verificarUbicacionLocal(disponibilidad, piso, j - 1);
            }
            break;
        case TRUE:
            if(j = 0 && i = 0) return verificarUbicacionLocal(disponibilidad, 0, 0);
            else if(j = 0){
                j = dimensiones_mall[1] - 1;
                return verificarUbicacionLocal(disponibilidad, i - 1, j);
            } 
            else{
                return verificarUbicacionLocal(disponibilidad, i, j) + 
                    verificarUbicacionLocal(disponibilidad, i, j - 1);
            }
            break;
        default: printf("Opcion invalida");
    }
}

void mostrarInformacionLocales(local_t **centroComercial, dis **availability, short piso, short dimensiones_mall[], 
    opc busqueda_piso_completa){

    int i, j;

    switch(busqueda_piso_completa){
        case FALSE:
            for(i = 0; i < dimensiones_mall[1]; i++){
                if(verificarUbicacionLocal(availability, piso - 1, i)){
                    printf("\n\n=========================\nNombre: %s\n", 
                    centroComercial[piso - 1][i].nombreLocal);
                    printf("Piso: %d Espacio en piso: %d\n", 
                    centroComercial[piso - 1][i].pisoLocal, 
                    centroComercial[piso - 1][i].numLocalxPiso);
                    printf("ID: %i\n\n", centroComercial[piso - 1][i].idLocal);
                }
            }
            break;
        case TRUE:
            for(i = 0; i < dimensiones_mall[0]; i++){
                for(j = 0; j < dimensiones_mall[1]; j++){
                    if(verificarUbicacionLocal(availability, i, j)){
                        printf("\n\n=========================\nNombre: %s\n", 
                        centroComercial[i][j].nombreLocal);
                        printf("Piso: %d Espacio en piso: %d\n", 
                        centroComercial[i][j].pisoLocal, 
                        centroComercial[i][j].numLocalxPiso);
                        printf("ID: %i\n\n", centroComercial[i][j].idLocal);
                    }
                }
            }
            break;
    }
}