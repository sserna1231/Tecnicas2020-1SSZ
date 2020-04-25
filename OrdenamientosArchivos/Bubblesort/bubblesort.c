#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* Arreglo, int longitud_arreglo){
	
	int 
	
		for(int i = 1; i < longitud_arreglo; i++){
			for(int j = 0; j < longitud_arreglo - i; j++){
				if(Arreglo[j] > Arreglo[j+1]){
					short fade = Arreglo[j];
					Arreglo[j] = Arreglo[j+1];
					Arreglo[j+1] = fade;
				}
			}
		}
}

int main(){
	
	int array[] = {1,3,2,6,2,7,5,9,3};
	
	bubbleSort(array, sizeof(array)/sizeof(int));
    printf("\n\n"); system("PAUSE");
	return 0;
}
