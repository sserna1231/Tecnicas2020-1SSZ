# include "selection.h"

float* reservarMemoria ( int N ){
	int i;
	float* Lista = malloc ( (N)*sizeof( float ));
	if (Lista != NULL ){
		return Lista;
	}else{
			printf("Reserva fallida\n");
			return NULL;
	}
}

void llenarMatriz ( float* Lista, int N ){
	int i;
	float num;
	for ( i=0; i<N; i++ ){
		printf("Elemento %i: ", i+1);
		scanf("%f", &num);
		Lista[i] = num;
	}
}

int buscarMenor ( float* Lista, int i, int N ){
	int menor = VALOR_MAYOR;
	int pos_menor;
	for ( ; i<N; i++ ){
		if ( Lista[i] <= menor ){/*Inicialmente cualquier valor será menor que VALOR_MAYOR; así que 
        automáticamente el menor éstará en la posición i*/
			menor = Lista[i];
			pos_menor = i;
		}
	}
	return pos_menor;
}

void intercambiar ( float* Lista, int i, int pos_menor ){
	float a, b; //Evitan que se pierdan los valores originales
	
	a = Lista[i];
	b = Lista[pos_menor];

	Lista[i] = b;
	Lista[pos_menor] = a;

}

void imprimirMatriz ( float* Lista, int N ){
	int i;
	for ( i=0; i<N; i++ ){
		printf("Elemento %i: %.2f\n", i+1, Lista[i]);
	}
}