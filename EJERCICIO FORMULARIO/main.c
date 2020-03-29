#include "formulario.h"

int main(){

    enum options opc;
    enum time_scala horizonte = YEAR;
    double secs;
    user usuario;
    //Estructura que guarda
    user server[12][5];

//Registro de usuarios (struct) en estructura estática: matriz 12*5
        do{
            //Despliegue de menu de bienvenida (opciones)
            
            printf("\n\t\tBienvenido querido usuario.\n\n");
            printf("Ingrese el numero respectivo de una de las siguientes"
            " actividades:\n\n");
            printf("1. Registrarse por primera vez en formulario.\n");
            printf("2. Ingresar mes de nacimiento\nEsta opcion le permite ver la informacion"
            " de los otros usuarios que ya se han registrado\ny nacieron en su mismo mes.\n");
            printf("3. Curiosidad recursiva\nEsta opcion le pide que ingrese su dia y mes de"
            " nacimiento y le dira cuantos segundos lleva\nen el planeta, aproximadamente.\n\n");
            printf("Presione la tecla \"0\" para salir\n\n");

            //Recibimiento de instruccion del usuario:
            printf("Digite su opcion: > ");
            scanf("%d", &opc);
                
                switch(opc){
                    case SALIR: 
                        printf("\nHasta luego\n");
                        break;
                    case LOG_IN:
                        verificarMesUsuario(&usuario);
                        if(verificarEspacio(server, usuario.mes)){
                            llenarForm(&usuario);
                            //Llenarform esta reiniciando el mes en  usuario
                            guardarNuevoUsuario(server, &usuario);
                            printf("\nRegistro llevado a cabo correctamente\n");
                            imprimirDatosUsuario(usuario);
                        } else{
                            printf("Lo sentimos, estimado usuario. No pudo registrarse debido a que"
                            " nuestro servidor esta lleno para su mes\n");
                        }
                        break;
                    case SHOW_INFO:
                        verificarMesUsuario(&usuario);
                        mostrarDatosMes(server, usuario.mes);
                        break;
                    case RECURSION:
                            llenarForm(&usuario);
                            secs = segundosActualidad(horizonte, usuario.year);
                            printf("Sabias %s que desde el anio en que naciste, han transcurrido"
                            " alrededor de %.0f segundos en el planeta!\n", usuario.name, secs);
                        break;
                    default: printf("Valor invalido\n");
                        break;
                }
        } while(opc);
    return 0;
}