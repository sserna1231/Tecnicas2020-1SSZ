#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* Arreglo, int longitud_arreglo){
	
	short fade; //Valor sombra
	short order; //Variable booleana
	
		for(int i = 1; i < longitud_arreglo; i++){
			order = 1;
            printf("Iteracion %d\n", i);
			for(int j = 0; j < longitud_arreglo - i; j++){
				if(Arreglo[j] > Arreglo[j+1]){
					fade = Arreglo[j];
					Arreglo[j] = Arreglo[j+1];
					Arreglo[j+1] = fade;
					order = 0;
					for(int k = 0; k < longitud_arreglo; k++) printf("%d ", Arreglo[k]);
	
	    			printf("\n\n");
				}
			}
			if(order) break;
		}
}

int main(){
	
	int array[] = {1,3,2,6,2,7,5,9,3};
	
	bubbleSort(array, sizeof(array)/sizeof(int));
    printf("\n\n"); system("PAUSE");
	return 0;
}
