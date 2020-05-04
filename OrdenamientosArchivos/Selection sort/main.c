#include "selection.h"

int main(){

    enum Prueba Test_size; 
    FILE *input = fopen("C:\\Users\\santiago serna\\Tecnicas2020-1SSZ\\OrdenamientosArchivos\\Arreglo_input.txt",
        "r");

    if(input){
        int test; //Tamano del input de cada prueba
        printf("Ingrese el numero del tipo de prueba:\n1. 10 elementos\n2. 100 elementos\n3. 1000"
            "\n4.10000\n5. +10000\n\n>>> ");
        scanf("%d", &test);

        switch(test){
            case 1:
                Test_size = FIRST;
                realizarTestSorting(input, Test_size, 0);
                break;
            case 2:
                Test_size = SECOND;
                realizarTestSorting(input, Test_size, 2);
                break;
            case 3:
                Test_size = THIRD;
                realizarTestSorting(input, Test_size, 4);
                break;
            case 4:
                Test_size = FOURTH;
                realizarTestSorting(input, Test_size, 6);
                break;
            case 5:
                Test_size = FIFHT;
                realizarTestSorting(input, Test_size, 8);
                break;
            default:
                printf("Opcion digitada invalida\n\n");
                return 1;
    	}
    }else{
        printf("No se abrio el archivo correactamente");
        return 1;
    }
    fclose(input);
    return 0;
}