# include "merge.h"

int main(){

	int N, n, j, i, grupos, ritmo, j1, j2, j3, salto, espacios1, espacios2;
	int* pj3 = &j3;
	printf("Cantidad de datos: ");
	scanf("%i", &N);

	n = niveles(N);

	int** Lista = reservarMemoria ( n, N );

	if ( n != 0 ){
		for ( j=0; j<N; j++ ){
			printf("Elemento %i: ", j+1);
			scanf("%i", &Lista[0][j]); //Los datos ingresados no serán evaluados en el siguiente ciclo
		}
		for ( i=1; i<=n; i++ ){ //La fila 0, no se cuenta como nivel i, tal que se imprimen valores en todos los niveles excepto en él
			salto = pow ( 2, i-1 ); //El salto, hace referencia a la posición de comparación de j2, es decir, mientras j1 es 0 j2 es j1 + salto
			*pj3 = 0; //j3 es la posición donde se imprimen los datos
			grupos = salto; //Los grupos son la cantidad de datos por bloque, tal que bloque1 es igual a bloque2 al comenzar a comparar
			ritmo = pow ( 2, i ); //El ritmo determina dónde hay un nuevo bloque1
			for ( j1=0; j1<N; j1+=ritmo ){
				j2 = j1; //Cuando comienza un nuevo bloque1, j2 es igual a j1
				*pj3 = j1; //Así mismo, se impieza a imprimir desde j1
				espacios1 = grupos; //Cantidad de datos del bloque 1
				espacios2 = grupos; //...bloque 2
				Lista = fasen ( Lista, i, N, salto, j1, j2, pj3, espacios1, espacios2 );
			}
		}
		printf("\n");
		for ( j=0; j<N; j++ ){
			printf("Elemento %i: %i\n", j+1, Lista[n][j]);
		}
	}
	return 0;
}