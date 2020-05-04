# include "selection.h"

int* reservarMemoria ( int N ){
	int i;
	int* Lista = malloc ( (N)*sizeof( int ));
	if (Lista != NULL ){
		return Lista;
	}else{
			printf("Reserva fallida\n");
			return NULL;
	}
}

void llenarMatriz ( int* Lista, int N ){
	int i;
	float num;
	for ( i=0; i<N; i++ ){
		printf("Elemento %i: ", i+1);
		scanf("%f", &num);
		Lista[i] = num;
	}
}

int buscarMenor ( int* Lista, int i, int N, int* comparaciones){
	int menor = VALOR_MAYOR;
	int pos_menor;
	for ( ; i<N; i++ ){
		if ( Lista[i] <= menor ){/*Inicialmente cualquier valor será menor que VALOR_MAYOR; así que 
        automáticamente el menor éstará en la posición i*/
        	(*comparaciones)++;
			menor = Lista[i];
			pos_menor = i;
		}
	}
	return pos_menor;
}

void intercambiar ( int* Lista, int i, int pos_menor, int* reposiciones){
	int a, b; //Evitan que se pierdan los valores originales
	
	a = Lista[i];
	b = Lista[pos_menor];

	Lista[i] = b;
	Lista[pos_menor] = a;
	(*reposiciones)++;
}

void imprimirMatriz ( int* Lista, int N ){
	int i;
	for ( i=0; i<N; i++ ){
		printf("Elemento %i: %d\n", i+1, Lista[i]);
	}
}

void selectionSort(int* Arreglo, int Longitud_arreglo, int operaciones[]){

	int i;
	int pos_menor; //Posición del menor valor de la lista

	if (Longitud_arreglo < 1){
		printf("Valor invalido\n");
	}else{

		for (i=0; i<Longitud_arreglo-1; i++){
			pos_menor = buscarMenor ( Arreglo, i, Longitud_arreglo, &operaciones[0]);
				if(pos_menor > i){
					intercambiar ( Arreglo, i, pos_menor, &operaciones[1]);
				}
		}
	}
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
                selectionSort(array, Test_size, estadisticas.operaciones);
                estadisticas.exec_time = (float) (clock() - t_init)/ CLOCKS_PER_SEC;
                estadisticas.fecha_fin = registroFecha();
                imprimirEstadisticas(&estadisticas, Test_size, "SelectionSort");
            } else{
                printf("Error leyendo los datos del arreglo\n\n");
            }
        }
    free(array);
    } else{
        printf("Error reservando la memoria\n\n");
    }   
}