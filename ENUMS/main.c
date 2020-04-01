#include <stdio.h>

typedef enum diasSemana{
	LUNES, MARTES, MIERCOLES, JUEVES, VIERNES
}dias_semana_e;

typedef enum estadoAnimo{
	CONTENTO = 1, ABURRIDO = 2, INDECISO = 3
}estado_animo_e;


void imprimirValorDiasSemana(dias_semana_e diaSemana){

	switch(diaSemana){
		case LUNES: printf("El dia es lunes \n");
					break;
        case MARTES: printf("El dia es martes \n");
					break;
        case MIERCOLES: printf("El dia es miercoles \n");
					break;
        case JUEVES: printf("El dia es jueves \n");
					break;
        case VIERNES: printf("El dia es viernes \n");
					break;
		default: printf("Estas de pachanga en fin de semana. ¿Cierto?");
					break;
	}

	if (diaSemana == LUNES){
		printf("ES lunes");
	}
    else if(diaSemana == MARTES)
        printf("Es martes");
    else if(diaSemana == MIERCOLES)
        printf("Es miercoles");
    else if(diaSemana == JUEVES)
        printf("Es jueves");
    else if(diaSemana == VIERNES)
        printf("Es viernes");
}


dias_semana_e llenarDiasSemana(){
	
    int i = 0;
    dias_semana_e diaUsuario;

 	printf("DIA\tNUMERO\n");
    while(i < sizeof(dias_semana_e) - 1){
        printf("%s\t%d", diaUsuario, diaUsuario);
        i++; diaUsuario++;
    }

    printf("Inserte de su dia (numero correspondiente):\n> ");
 	scanf("%d", &diaUsuario);
 	return diaUsuario;
}

/* COMPLETE: mejore el codigo de llenar DiasSemanas para que le pida datos al
usuario mientras que el valor ingresado sea menor a 0 o mayor a 6 pues significaría que
no esta en el rango de los días de la semana definidos */

dias_semana_e llenarDiasSemanaMejorado(){
    
    int diaUsuario = NULL, i = 0;

    printf("DIA\tNUMERO\n");
    for(; i < 5; i++, diaUsuario++) printf("%i\t%s", i, diaUsuario);

    do{
        printf("Inserte el dia:\n> ");
        scanf("%d", &diaUsuario);
            if(diaUsuario < 0 || diaUsuario > 4) 
                printf("Valor invalido. Digite de nuevo");
    } while(diaUsuario < 0 || diaUsuario > 4);

    switch(diaUsuario){
        case LUNES: printf("El dia es lunes");
                    break;
        case MARTES: printf("El dia es martes");
                    break;
        case MIERCOLES: printf("El dia es miercoles");
                    break;
        case JUEVES: printf("El dia es jueves");
                    break;
        case VIERNES: printf("El dia es viernes");
                    break;
    }
    return diaUsuario;
}

void mostrarMensajeEstadoAnimo(){

	estado_animo_e estadoAnimo = 0;
	printf("Qué estado de animo tiene: ");
	scanf("%d", &estadoAnimo);

	// Ejemplo solo con IF y valores representados como enteros
	/*if (estadoAnimo == 1) {
		printf ("Felicitaciones una actitud positiva es importante \n");
	} else if (estadoAnimo == 2){ 
		printf ("No se deprima, la vida es bella \n");
	} else if (estadoAnimo == 3){ 
		printf("Tranquilo, pongase contento \n");
	}*/

	// Ejemplo con valores del enum
	if (estadoAnimo == 	CONTENTO){
		printf ("Felicitaciones una actitud positiva es importante \n");
	}else if (estadoAnimo == ABURRIDO){ 
		printf ("No se deprima, la vida es bella \n");
	}

	// Ejemplo con valores del enum y switch case
	switch (estadoAnimo){
		case CONTENTO: printf("MENSAJE CUANDO ESTA CONTENTO \n");
						break;
		case ABURRIDO: printf("Mensaje cuando esta ABURRIDO \n");
						break;
		case INDECISO: printf("Mensaje para indecisos \n" );
						break;
	}

}

int main()
{
	// Descomente este codigo para que pueda probar las otras operaciones
	dias_semana_e dia = llenarDiasSemana();
    dias_semana_e day = llenarDiasSemanaMejorado();
	imprimirValorDiasSemana(dia);
    imprimirValorDiasSemanaMejorado(day);
	mostrarMensajeEstadoAnimo();
	return 0;
}