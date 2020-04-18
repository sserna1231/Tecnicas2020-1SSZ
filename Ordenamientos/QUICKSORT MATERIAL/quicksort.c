#include <stdio.h>
#include <stdlib.h>

void quickSort(int* Arreglo, int longitud_arreglo){
	
	int	i = 0, j = longitud_arreglo - 1;
	int pivote = Arreglo[longitud_arreglo/2];
	
	if(longitud_arreglo < 2) return;
	
	for(int k = 0; k < longitud_arreglo; k++) printf("%d ", Arreglo[k]);
    printf("\n");
	
    printf("len: %d\tpivote: %d\n", longitud_arreglo, pivote);

    for(;;i++, j--){
        
        while(Arreglo[i] < pivote) i++;
		while(Arreglo[j] > pivote) j--;

        if(i >= j) break;
        
		int fade = Arreglo[i];
		Arreglo[i] = Arreglo[j];
		Arreglo[j] = fade;

    }

    quickSort(Arreglo, i);
    quickSort(Arreglo + i, longitud_arreglo - i);
}

int main(){
	
	int array[] = {5, 7, 3, 1, 8, 6, 4, 1};
	
	quickSort(array, sizeof(array)/sizeof(int));
	
	for(int i = 0; i < sizeof(array)/sizeof(int); i++) printf("%d ", *(array + i));
	
	printf("\n\n"); system("PAUSE");
	return 0;
}
