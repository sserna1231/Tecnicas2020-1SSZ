#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Algoritmo iterativo de ordenamiento burbuja
void bubbleSort(int* Arreglo, int longitud_arreglo, int operaciones[]);

//Struct de las estadísticas
typedef struct Statistics_execution{
    char* fecha_init;
    char* fecha_fin;
    float exec_time;
    int operaciones[2]; //Comparaciones, reposiciones
} stat;

//Este enum representa el orden de prueba con el tamanio del arreglo
enum Prueba{
FIRST = 10, SECOND = 100, THIRD = 1000, FOURTH = 10000,
FIFHT = 25000
};

//Realiza la prueba requerida para el tamaño de arreglo especificado por el enum
void realizarTestSorting(FILE *Archivo_input, short Test_size, short new_lines);

//Imprime las estadísticas de una prueba
void imprimirEstadisticas(stat *estadisticas_prueba, int Test_size, char* Algoritmo_name);

/*Devuelve una cadena con la fecha y hora exactas en el momento de su llamada,
en formato dd/mm/yyyy h/min/s*/
char* registroFecha(void);

//Algoritmo recursivo quicksort
void quickSort(int* Arreglo, int longitud_arreglo, int operaciones[]);

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

char* registroFecha(void){
    typedef struct tm tm;

    time_t t_init = time(NULL);
    tm* fecha;
    //Será una cadena de 50 char's. Revisese el struct stat
    char* date = calloc(50, sizeof(char));

    if(date){
        fecha = localtime(&t_init);
        strftime(date,50,"Fecha: %d/%m/%Y Hora: %H:%M:%S",fecha);
        return date;
    } else{
        printf("Error obteniendo la memoria necesaria\n\n");
        date = registroFecha();
        return date;
    }
}

void imprimirEstadisticas(stat *estadisticas_prueba, int Test_size, char* Algoritmo_name){

    FILE *output = fopen("C:\\Users\\santiago serna\\Tecnicas2020-1SSZ\\OrdenamientosArchivos\\Arreglo_output.txt",
        "a");

    if(output){
        fprintf(output, "%s\n", Algoritmo_name);
        fprintf(output, "===============================================\n");
        fprintf(output, "Inicio>\n%s\n", estadisticas_prueba->fecha_init);
        fprintf(output, "Final>\n%s\n", estadisticas_prueba->fecha_fin);
        fprintf(output, "Final>\n%s\n", estadisticas_prueba->fecha_fin);
        fprintf(output, "Tiempo de ejecucion: %.4f segundos\n", estadisticas_prueba->exec_time);
        fprintf(output, "Cantidad de comparaciones: %d\n", estadisticas_prueba->operaciones[0]);
        fprintf(output, "Cantidad de reposiciones: %d\n", estadisticas_prueba->operaciones[1]);
        fprintf(output, "===============================================\n\n");
    } else{
        printf("Error abriendo el archivo\n\n");
        printf("No se pudo imprimir las estadisticas\n\n");
    }
    fclose(output);
}

void realizarTestSorting(FILE *Archivo_input, short Test_size, short new_lines){

    stat estadisticas;
    int *array = malloc(Test_size * sizeof(int));

    if(array){
        //Por cada prueba se repite dos veces para cada arreglo
        for(int i = 1; i <= 2; i++){
            int data = 0; //Cantidad de datos leidos
            char c;
            //Inicializacion de contador de operaciones
            estadisticas.operaciones[0] = 0; estadisticas.operaciones[1] = 0;

            while(new_lines && !feof(Archivo_input)){
                c = fgetc(Archivo_input);
                    if(c == '\n') new_lines--;
            }
 
            for(int j = 0; j < Test_size; j++){
                data += fscanf(Archivo_input, "%d", &array[j]);
            }

            if(data == Test_size){
                fseek(Archivo_input, 1, SEEK_CUR);
                time_t t_init = clock();
                estadisticas.fecha_init = registroFecha();
                bubbleSort(array, Test_size, estadisticas.operaciones);
                estadisticas.exec_time = (float) (clock() - t_init)/ CLOCKS_PER_SEC;
                estadisticas.fecha_fin = registroFecha();
                imprimirEstadisticas(&estadisticas, Test_size, "BubbleSort");
            } else{
                printf("Error leyendo los datos del arreglo\n\n");
            }
        }
    free(array);
    } else{
        printf("Error reservando la memoria\n\n");
    }   
}
void bubbleSort(int* Arreglo, int longitud_arreglo, int operaciones[]){
	
    int rep = 0;//Contador de comparaciones y reposiciones
	float potencia = (pow(longitud_arreglo, 2) - longitud_arreglo)/2;
	operaciones[0] = (int) potencia;

		for(int i = 1; i < longitud_arreglo; i++){
			for(int j = 0; j < longitud_arreglo - i; j++){
				if(Arreglo[j] > Arreglo[j+1]){
					short fade = Arreglo[j];
					Arreglo[j] = Arreglo[j+1];
					Arreglo[j+1] = fade;
                    operaciones[1]++;
				}
			}
		}
}      

 