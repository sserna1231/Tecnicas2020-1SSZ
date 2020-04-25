para ( nivel=1; nivel<=niveles; nivel++ ){
	salto = 2^(n-1);
	grupos = salto;
	ritmo = 2^n;
	j3 = 0;
	para ( j1=0; j1<N; j1+=ritmo ){
		j2 = j1;
		espacios1 = grupos;
		espacios2 = grupos;
		fasen ( salto, j1, j2, j3, espacios1, espacios2 );
	}
}

fasen ( Lista, n, N, salto, j1, j2, j3, espacios1, espacios2 ){

	int contador;

	si ( espacios1 == 0 || espacios2 == 0 ){
		si ( espacios1 == 0 ){
			contador = espacios2;
			do{
				Lista[n][j3] = Lista[n-1][j2];
				Lista[n-1][j2] = NULO;
				j2 = j2 + 1;
				j3 = j3 + 1;
				contador = contador - 1;
			} while( contador != 0 );
			return 0;
		}si no{
			contador = espacios1;
			do{
				Lista[n][j3] = Lista[n-1][j1];
				Lista[n-1][j1] = NULO;
				j1 = j1 + 1;
				j3 = j3 + 1;
				contador = contador - 1;
			} while( contador != 0 );
			return 0;
		}
	}si no{
		Lista[n-1][j1];
			si ( espacios1 == espacios2 && j1 == j2 ){	//CASO ÚNICO Y ES EL INICIAL
				j2 = j2 + salto;

				si ( j1-1 + espacios1 >= N ){ //EL BLOQUE 1 ESTÁ INCOMPLETO
				espacios1 = 0;
				do {
					si ( j1 < N ){
						espacios1 = espacios1 + 1;
						j1 = j1 + 1;
					}
				}while ( j1 < N );
				espacios2 = 0;
				fasen ( Lista, n, N, salto, j1, j2, j3, espacios1, espacios2 );
				}

				si ( j2-1 + espacios2 >= N ){	//EL BLOQUE 2 ESTÁ INCOMPLETO
					espacios2 = 0;
					do {
						if ( j2 < N ){
							espacios2 = espacios2 + 1;
							j2 = j2 + 1;
						}
					}while ( j2 < N );
					fasen ( Lista, n, N, salto, j1, j2, j3, espacios1, espacios2 );
				}

			}
			Lista[n-1][j2];
			si ( Lista[n-1][j1] >= Lista[n-1][j2] ){
				Lista[n][j3] = Lista[n-1][j2];
				Lista[n-1][j2] = NULO;
				j2 = j2 +1;
				j3 = j3 + 1;
				espacios2 = espacios2 - 1;
				return fasen ( Lista, n, N, salto, j1, j2, j3, espacios1, espacios2 );
			}si no{
				Lista[n][j3] = Lista[n-1][j1];
				Lista[n-1][j1] = NULO;
				j1 = j1 + 1;
				j3 = j3 + 1;
				espacios1 = espacios1 - 1;
				return	fasen ( Lista, n, N, salto, j1, j2, j3, espacios1, espacios2 );
			}	
	}
}