#include "formulario.h"

void llenarForm(user* usuario_nuevo){
	
	int i;
	mes nacimiento;

	printf("Ingrese su nombre. Asegurese de no ingresar mas" 
    " de 30 caracteres:\n> ");
	fgets(usuario_nuevo->name, 30, stdin); fflush(stdin);
	
    //Verificacion de valor de dia
    do{
	printf("Ingrese su dia de nacimiento:\n> ");
    scanf("%d", &usuario_nuevo->dia);
        if(usuario_nuevo->dia < 1 || usuario_nuevo->dia > 30)
            printf("Valor invalido\n");
    } while(usuario_nuevo->dia < 1 || usuario_nuevo->dia > 30);

    //Verificacion del anio de nacimiento
        do{    
            printf("Ingrese su anio de nacimiento:\n> ");
            scanf("%d", &usuario_nuevo->year);
                if(usuario_nuevo->year < 1910) printf("Valor invalido."
                "Es muy poco probable que siga vivo\n");
                if(usuario_nuevo->year > 2020) printf("Valor invalido."
                "El anio ingresado aun no acontece\n");
        } while(usuario_nuevo->year < 1910 || usuario_nuevo->year > 2020);

	//Reemplazo del new line caracter que inserta fgets
	for(i = 0; i < 30; i++){
		if(usuario_nuevo->name[i] == '\n')
			usuario_nuevo->name[i] = 0;
		if(usuario_nuevo->name[i] == '\n')
			usuario_nuevo->name[i] = 0;
	}
}

void imprimirDatosUsuario(user usuario_nuevo){
    printf("\nRegistro llevado a cabo correctamente\n");
	printf("------------------------------\n");
	printf("Nombre: %s \n", usuario_nuevo.name);
	printf("Dia de nacimiento:%d \n", usuario_nuevo.dia);
	printf("Mes de nacimiento:%d \n", usuario_nuevo.mes);
    printf("Anio de nacimiento:%d \n", usuario_nuevo.year);
}