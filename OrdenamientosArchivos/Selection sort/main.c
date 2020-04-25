# include "selection.h"

int main(){

	int N; //Cantidad de datos
	int i;
	int pos_menor; //Posición del menor valor de la lista
	printf("Cantidad de datos: ");
	scanf("%i", &N);
	if ( N<= 0 ){
		printf("Valor invalido\n");
	}else{
		float* Arreglo = reservarMemoria (N);
		llenarMatriz ( Arreglo, N );
		for ( i=1; i<N; i++ ){
			pos_menor = buscarMenor ( Arreglo, i, N );
			intercambiar ( Arreglo, i, pos_menor );
		}
		printf("\n");

		imprimirMatriz( Arreglo, N );
	}
	return 0;
}