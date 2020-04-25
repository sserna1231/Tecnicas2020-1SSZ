# include "merge.h"

int** reservarMemoria ( int n, int N ){
	int i;
	int** Lista = malloc ( (n+1)*sizeof( int* ));
	if (Lista != NULL ){
		for ( i=0; i<(n+1); i++ ){
			Lista[i] = malloc ( N*sizeof( int ));
		}
	}else{
			printf("Reserva fallida\n");
			return 0;
	}
	return Lista;
}

int niveles ( int N ){
	int n = 0;
	int i = 1;
	do{
		if ( N/2 <= pow( 2, i-1 )){
			n = i;
		}else{
			i += 1;
		}
	}while ( n == 0 );
	//Determina si la cantidad de datos es par
	if ( N%2 != 0 ){
		return n+1;
	}else{
		return n;
	}
}

int** fasen ( int** Lista, int n, int N, int salto, int j1, int j2, int* pj3, int espacios1, int espacios2 ){

	int contador;

	if ( espacios1 == 0 || espacios2 == 0 ){ //si alguno de los bloques está ya sin valores, procede
		if ( espacios1 == 0 ){
			contador = espacios2; //el bloque 1 ya no tiene valores
			while( contador != 0 && *pj3 < N ){ //Ya que todo está ordenado en el bloque2, se imprime sin más
				Lista[n][*pj3] = Lista[n-1][j2];
				Lista[n-1][j2] = NULO;
				j2 = j2 + 1;
				*pj3 = *pj3 + 1; 
				contador = contador - 1; //Hasta que ya no queden valores en el bloque2
			}
			return Lista;
		}else{
			contador = espacios1;//el bloque 2 ya no tiene valores
			while( contador != 0 && *pj3 < N ){ //Ya que todo está ordenado en el bloque1, se imprime sin más
				Lista[n][*pj3] = Lista[n-1][j1];
				Lista[n-1][j1] = NULO;
				j1 = j1 + 1;
				*pj3 = *pj3 + 1;
				contador = contador - 1; //Hasta que ya no queden valores en el bloque1
			}
			return Lista;
		}
	}else{
		Lista[n-1][j1]; //Se selecciona el valor en j1
			if ( espacios1 == espacios2 && j1 == j2 ){	//CASO ÚNICO Y ES EL INICIAL
				j2 = j2 + salto;

				if ( j1-1 + espacios1 >= N ){ //EL BLOQUE 1 ESTÁ INCOMPLETO
				espacios1 = 0;
				while ( j1 < N ){
					if ( j1 < N ){
						espacios1 = espacios1 + 1;
						j1 = j1 + 1;
					}
				}
				espacios2 = 0;
				j1 = j1 - espacios1;
				Lista = fasen ( Lista, n, N, salto, j1, j2, pj3, espacios1, espacios2 );
				}

				if ( j2-1 + espacios2 >= N ){ //EL BLOQUE 2 ESTÁ INCOMPLETO
					espacios2 = 0;
					while ( j2 < N ){
						if ( j2 < N ){
							espacios2 = espacios2 + 1;
							j2 = j2 + 1;
						}
					}
					j2 = j2 - espacios2;
					Lista = fasen ( Lista, n, N, salto, j1, j2, pj3, espacios1, espacios2 );
				}

			}
			Lista[n-1][j2]; // Se selecciona el valor en j2
			if ( Lista[n-1][j1] >= Lista[n-1][j2] && *pj3 < N ){
				Lista[n][*pj3] = Lista[n-1][j2];
				Lista[n-1][j2] = NULO;
				j2 = j2 +1;
				*pj3 = *pj3 + 1;
				if ( *pj3 < N ){ //Mientras no imprima fuera del espacio, procede
					espacios2 = espacios2 - 1;
					Lista = fasen ( Lista, n, N, salto, j1, j2, pj3, espacios1, espacios2 );
				}else{
					return Lista;
				}
			}else{	
				Lista[n][*pj3] = Lista[n-1][j1];
				Lista[n-1][j1] = NULO;
				j1 = j1 + 1;
				*pj3 = *pj3 + 1;
				if ( *pj3 < N ){
					espacios1 = espacios1 - 1;
					Lista = fasen ( Lista, n, N, salto, j1, j2, pj3, espacios1, espacios2 );
				}else{
					return Lista;
				}
			}	
	}
}
