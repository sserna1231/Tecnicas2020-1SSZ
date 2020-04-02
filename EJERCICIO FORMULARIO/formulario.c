#include "formulario.h"

void verificarMesUsuario(user* usuario){

    mes nacimiento;
    
    do{
        printf("Ingrese su mes de nacimiento:\n> ");
        scanf("%d", &nacimiento);

        switch(nacimiento){
            case ENERO: usuario->mes = nacimiento;
                        break;
            case FEBRERO: usuario->mes = nacimiento;
                        break;
            case MARZO: usuario->mes = nacimiento;
                        break;
            case ABRIL: usuario->mes = nacimiento;
                        break;
            case MAYO: usuario->mes = nacimiento;
                        break;
            case JUNIO: usuario->mes = nacimiento;
                        break;
            case JULIO: usuario->mes = nacimiento;
                        break;
            case AGOSTO: usuario->mes = nacimiento;
                        break;
            case SEPTIEMBRE: usuario->mes = nacimiento;
                        break;
            case OCTUBRE: usuario->mes = nacimiento;
                        break;
            case NOVIEMBRE: usuario->mes = nacimiento;
                        break;
            case DICIEMBRE: usuario->mes = nacimiento;
                        break;
            default: printf("Valor invalido\n");
        }
    } while(nacimiento < 1 || nacimiento > 12);                            
}


void llenarForm(user* usuario_nuevo){
	
	int i;

	printf("Ingrese su nombre. Asegurese de no ingresar mas" 
    " de 30 caracteres:\n> "); fflush(stdin);
	fgets(usuario_nuevo->name, 30, stdin); fflush(stdin);
	
    //Verificacion de valor de dia
    do{
	printf("Ingrese su dia de nacimiento:\n> ");
    scanf("%hi", &usuario_nuevo->dia);
        if(usuario_nuevo->dia < 1 || usuario_nuevo->dia > 30)
            printf("Valor invalido\n");
    } while(usuario_nuevo->dia < 1 || usuario_nuevo->dia > 30);

    //Verificacion del anio de nacimiento
        do{    
            printf("Ingrese su anio de nacimiento:\n> ");
            scanf("%hi", &usuario_nuevo->year);
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
    
	printf("------------------------------\n");
	printf("Nombre: %s \n", usuario_nuevo.name);
	printf("Dia de nacimiento:%d \n", usuario_nuevo.dia);
	printf("Mes de nacimiento:%d \n", usuario_nuevo.mes);
    printf("Anio de nacimiento:%d \n", usuario_nuevo.year);
}

void guardarNuevoUsuario(user Matriz[][5], user* nuevo_registro_usuario){

    int j;

    for(j = 0; j < 5; j++){
        if(Matriz[nuevo_registro_usuario->mes][j].name[0] == '\0'){
            Matriz[nuevo_registro_usuario->mes][j] = *nuevo_registro_usuario;
            printf("%s %d %d %d", Matriz[nuevo_registro_usuario->mes][j].name,
            Matriz[nuevo_registro_usuario->mes][j].dia, Matriz[nuevo_registro_usuario->mes][j].mes
            , Matriz[nuevo_registro_usuario->mes][j].year);
            break;
        }
    }
}

int verificarEspacio(user Matriz[][5], short mes){

    int j;

    for(j = 0; j < 5; j++){
        if(Matriz[mes - 1][j].name[0] == '\0')
            return 1;
    }
    return 0;
}

void mostrarDatosMes(user Matriz[][5], short mes){

    int j = 0;

    while(Matriz[mes - 1][j].name[0]){
        imprimirDatosUsuario(Matriz[mes - 1][j]);
        j++;
    }
}

double segundosActualidad(enum time_scala tiempo_buscado, int tiempo_interes){

    struct tm *secs;
    time_t tiempo;
    tiempo = time(NULL);
    secs = localtime(&tiempo);
    
    switch(tiempo_buscado){
        case DAY:
            if(tiempo_interes == secs->tm_mday){
                return secs->tm_hour*3600 + secs->tm_min*60 + secs->tm_sec;
            }else{
                return DIA_SEC + segundosActualidad(DAY, tiempo_interes + 1);
            }
            break;
        case MONTH:
            if(tiempo_interes == secs->tm_mon){
                return segundosActualidad(MONTH + 1, 1);
            }else{
                return MONTH_SEC + segundosActualidad(MONTH, tiempo_interes + 1);
            }
            break;
        case YEAR:
            if(tiempo_interes == secs->tm_year + 1900){
                return segundosActualidad(YEAR + 1, 0);
            }else{
                return YEAR_SEC + segundosActualidad(YEAR, tiempo_interes + 1);
            }
            break;
    }
}