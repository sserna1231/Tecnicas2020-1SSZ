#include "formulario.h"

int main(){

    enum options opc;
    user* new_user; 
    short nacimiento;
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
            scanf("%i", &opc);
                
                switch(opc){
                    case SALIR: printf("Hasta luego");
                        break;
                    case LOG_IN:
                        //Verificacion de valor de mes
                        /*Esto se hace para tener de una vez el mes del potencial usuario
                        en caso de que pase la verificacion de espacio en la matriz, pero 
                        tambien para pasar esto como el argumento para la funcion que verifica*/
                        do{
                            printf("Ingrese su mes de nacimiento:\n> ");
                            scanf("%d", &nacimiento);
                            switch(nacimiento){
                                case ENERO: new_user->mes = nacimiento;
                                            break;
                                case FEBRERO: new_user->mes = nacimiento;
                                            break;
                                case MARZO: new_user->mes = nacimiento;
                                            break;
                                case ABRIL: new_user->mes = nacimiento;
                                            break;
                                case MAYO: new_user->mes = nacimiento;
                                            break;
                                case JUNIO: new_user->mes = nacimiento;
                                            break;
                                case JULIO: new_user->mes = nacimiento;
                                            break;
                                case AGOSTO: new_user->mes = nacimiento;
                                            break;
                                case SEPTIEMBRE: new_user->mes = nacimiento;
                                            break;
                                case OCTUBRE: new_user->mes = nacimiento;
                                            break;
                                case NOVIEMBRE: new_user->mes = nacimiento;
                                            break;
                                case DICIEMBRE: new_user->mes = nacimiento;
                                            break;
                                default: printf("Valor invalido\n");
                            }
                        } while(nacimiento < 1 || nacimiento > 12);

                        if(/*Funcion de lucas dice que si hay espacio*/){
                            llenarForm(new_user);
                            imprimirDatosUsuario(*new_user);
                        } else{
                            printf("Lo sentimos, estimado usuario. No pudo registrarse debido a que"
                            " nuestro servidor esta lleno para su mes\n");
                        }
                        break;
                    case SHOW_INFO:
                        /*Proceso de muestra de datos de mes*/
                        break;
                    case RECURSION:
                        break;
                    default: printf("Valor invalido\n");
                        break;
                }
        } while(opc);
}