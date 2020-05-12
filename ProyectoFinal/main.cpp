#include "FuncionesCC.h"
#include <stdio.h>

int main(){
    
    local_t **mall; //Mall es centro comercial en ingles
    dis **disponibilidad;
    short  dimensiones[2];
    short dir_local[2];
    srand(time(NULL));
    short opcion; 
    short sub_opc;
    short piso;
    dis estado_ocupacion = OCUPADO;

    printf("\tBienvenido al software de administracion de centros comerciales\n");
    printf("\t\t\tMallAdministrator v1.0\n\n");
    printf("Primero, se requiere que el usuario ingrese las dimensiones de su mall\n"
        "para asi inicializar el software y su base de datos.\n\n");
    determinarDimensionesMall(dimensiones);
    mall = construirCentroComercial(dimensiones);
    disponibilidad = alocarEspacioMatrizDisponibilidad(dimensiones);
    //Mostrar menu:
            do{
                printf("\nPresione entre una de las siguientes opciones:\n\n");
                printf("1. Registrar nuevo local\n2. Consultar ocupacion del mall\n3. Mostrar"
                    " informacion de locales\n4. Editar informacion de un local especifico\n5. Borrar local\n"
                    "0. Salir\n\n");
                printf("> "); scanf("%hd", &opcion);
                switch(opcion){
                    case 1: 
                        determinarDireccionLocal(dir_local, dimensiones);
                        if(!verificarUbicacionLocal(disponibilidad, dir_local[0], dir_local[1])){
                            establecerNuevoLocal(mall, dir_local);
                            establecerDisponibilidad(disponibilidad, estado_ocupacion, dir_local);
                            mostrarLocal(mall, disponibilidad, dir_local[0], dir_local[1]);
                            printf("Nuevo local guardado correctamente\n");
                        } else{
                            printf("Direccion ocupada dentro del mall\n");
                        }
                        break;
                    case 2:
                        printf("Digite segun el caso\n\n0. Ocupacion en piso\n1. Ocupacion global"
                            "\n\n> "); scanf("%hd", &sub_opc);
                        switch(sub_opc){
                            case 0: 
                                printf("Digite el piso de interes\n> ");
                                scanf("%hd", &piso);
                                printf("El espacio disponible en el piso %hd es de %hd.\n\n", piso, 
                                    dimensiones[1] - reportarEspacioDisponible(disponibilidad, dimensiones, piso, FALSE));
                                break;
                            case 1:
                                printf("El espacio dispoible en el mall es de %hd.\n\n",         
                                dimensiones[1]*dimensiones[0] - reportarEspacioDisponible(disponibilidad, dimensiones, 0, TRUE));
                                break;
                            default: printf("Opcion invalida\n\n");
                        }
                        break;
                    case 3:
                        printf("Digite segun el caso\n\n0. Locales de piso especificado\n1. Ocupacion global"
                            "\n\n> "); scanf("%hd", &sub_opc);
                        switch(sub_opc){
                            case FALSE: 
                                printf("Digite el piso de interes\n> ");
                                scanf("%hd", &piso);
                                mostrarInformacionLocales(mall, disponibilidad, piso, dimensiones, FALSE);
                                break;
                            case TRUE:
                                mostrarInformacionLocales(mall, disponibilidad, 0, dimensiones, TRUE);
                                break;
                            default: printf("Opcion invalida\n\n");
                        }
                        break;
                    case 4:
                        determinarDireccionLocal(dir_local, dimensiones);
                        editarInfoLocal(mall, disponibilidad, dir_local[0], dir_local[1], dimensiones);
                        break;
                    case 5:
                        determinarDireccionLocal(dir_local, dimensiones);
                        establecerDisponibilidad(disponibilidad, DESOCUPADO, dir_local);
                        break;
                    case 0: printf("Vuelva pronto...\n\n");
                        printf("Cerrando programa\n"); system("PAUSE");
                }
            }while(opcion); 

    free(mall); free(disponibilidad);
    return 0;
}