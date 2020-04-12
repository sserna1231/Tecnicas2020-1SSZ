#include "FuncionesCC.h"
#include <stdio.h>

int main(){
    
    local_t **mall; //Mall es centro comercial en ingles
    dis **disponibilidad;
    short  dimensiones[2];
    short dir_local[2];
    srand(time(NULL));

    printf("\t\tBienvenido al software de administracion de centros comerciales\n");
    printf("\t\t\tMallAdministrator v1.0\n\n");
    printf("Primero, se requiere que el usuario ingrese las dimensiones de su mall\n"
        "para asi inicializar el software y su base de datos.\n");
    determinarDimensionesMall(dimensiones);
    mall = construirCentroComercial(dimensiones);
    disponibilidad = alocarEspacioMatrizDisponibilidad(dimensiones);
    //Mostrar menu:
            do{
                determinarDireccionLocal(dir_local, dimensiones);
                if(!verificarUbicacionLocal(disponibilidad, dir_local)){
                    establecerNuevoLocal(mall, dir_local);
                    printf("Nombre: %s\nPiso: %d\nEspacio: %d\nID: %p\n",
                        mall[dir_local[0] - 1][dir_local[1] - 1].nombreLocal,mall[dir_local[0] -1][dir_local[1] - 1].pisoLocal,
                        mall[dir_local[0] - 1][dir_local[1] - 1].numLocalxPiso, mall[dir_local[0] - 1][dir_local[1] - 1].idLocal);
                    establecerDisponibilidad(disponibilidad, OCUPADO, dir_local);
                    printf("disponibilidad: %hd\n", disponibilidad[dir_local[0] - 1][dir_local[1] - 1]);
                    printf("Nuevo local guardado correctamente\n");
                } else{
                    printf("Direccion ocupada dentro del mall\n");
                }
            }while(1); 
        /*-Operacion 1: Mostrar el espacio disponible en todo el edificio y por piso
        -Operacion 2: Mostrar el nombre de los locales por piso o alguno en especifico
        -Editar info local
        -Eliminar local
        -Opcion salida con EOF
            liberar en main la memoria dinamica
*/
    free(mall); free(disponibilidad);
    return 0;
}