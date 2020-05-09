#include "pruebas.h"

void menuPruebas(const char* Algoritmo){

    enum Prueba Test_size; 
    FILE *input = fopen("C:\\Users\\santiago serna\\Tecnicas2020-1SSZ\\OrdenamientosArchivos\\Arreglo_input.txt",
        "r");

    if(input){
        int test; //Tamano del input de cada prueba
        printf("Ingrese el numero del tipo de prueba:\n1. 10 elementos\n2. 100 elementos\n3. 1000"
            "\n4. 10000\n5. +10000\n\n>>> ");
        scanf("%d", &test);

        switch(test){
            case 1:
                Test_size = FIRST;
                realizarTestSorting(input, Test_size, 0, Algoritmo);
                break;
            case 2:
                Test_size = SECOND;
                realizarTestSorting(input, Test_size, 2, Algoritmo);
                break;
            case 3:
                Test_size = THIRD;
                realizarTestSorting(input, Test_size, 4, Algoritmo);
                break;
            case 4:
                Test_size = FOURTH;
                realizarTestSorting(input, Test_size, 6, Algoritmo);
                break;
            case 5:
                Test_size = FIFHT;
                realizarTestSorting(input, Test_size, 8, Algoritmo);
                break;
            default:
                printf("Opcion digitada invalida\n\n");
        }
    }else{
        printf("No se abrio el archivo correactamente");
    }
    fclose(input);
}

void realizarTestSorting(FILE *Archivo_input, int Test_size, short new_lines, const char* Algoritmo){

    stat estadisticas;
    int *array = malloc(Test_size * sizeof(int));

    if(array){
        //Por cada prueba se repite dos veces para cada arreglo
        for(int i = 1; i <= 2; i++){
            int data = 0; //Cantidad de datos leidos
            char c;
            //Inicializacion de contador de operaciones
            estadisticas.operaciones[0] = 0; estadisticas.operaciones[1] = 0;
            estadisticas.operaciones[2] = 0;

            while(new_lines && !feof(Archivo_input)){
                c = fgetc(Archivo_input);
                    if(c == '\n') new_lines--;
            }
 
            for(int j = 0; j < Test_size; j++){
                data += fscanf(Archivo_input, "%d", &array[j]);
            }

            if(data == Test_size){
                fseek(Archivo_input, 1, SEEK_CUR);
                estadisticas.fecha_init = registroFecha();
                time_t t_init = clock();
                switch(*Algoritmo){
                    case 'Q':
                        printf("Ejecutando Algoritmo Quicksort...\n\n");
                        quickSort(array, Test_size, estadisticas.operaciones);
                        break;
                    case 'S':
                        printf("Ejecutando Algoritmo selectionSort...\n\n");
                        selectionSort(array, Test_size, estadisticas.operaciones);
                        break;
                    case 'B':
                        printf("Ejecutando Algoritmo BubbleSort...\n\n");
                        bubbleSort(array, Test_size, estadisticas.operaciones);
                        break;
                    case 'F':
                        printf("Ejecutando Algoritmo BubbleSort mejorado...\n\n");
                        bubbleSortFixed(array, Test_size, estadisticas.operaciones);
                        break;
                    default:
                        printf("Algoritmo irreconocido\n\n");
                }
                estadisticas.exec_time = (float) (clock() - t_init)/ CLOCKS_PER_SEC;
                estadisticas.fecha_fin = registroFecha();
                imprimirEstadisticas(&estadisticas, Test_size, Algoritmo);
            } else{
                printf("Error leyendo los datos del arreglo\n\n");
            }
        }
    free(array);
    } else{
        printf("Error reservando la memoria\n\n");
    }   
}

void imprimirEstadisticas(stat *estadisticas_prueba, int Test_size, const char* Algoritmo_name){

    FILE *output = fopen("C:\\Users\\santiago serna\\Tecnicas2020-1SSZ\\OrdenamientosArchivos\\Arreglo_output.txt",
        "a");

    if(output){
        fprintf(output, "%s\n", Algoritmo_name);
        fprintf(output, "===============================================\n");
        fprintf(output, "Inicio>\n%s\n", estadisticas_prueba->fecha_init);
        fprintf(output, "Final>\n%s\n", estadisticas_prueba->fecha_fin);
        fprintf(output, "Final>\n%s\n", estadisticas_prueba->fecha_fin);
        fprintf(output, "Tiempo de ejecucion: %.10f segundos\n", estadisticas_prueba->exec_time);
        fprintf(output, "Cantidad de iteraciones (si aplica): %d\n", estadisticas_prueba->operaciones[2]);
        fprintf(output, "Cantidad de comparaciones: %d\n", estadisticas_prueba->operaciones[0]);
        fprintf(output, "Cantidad de reposiciones: %d\n", estadisticas_prueba->operaciones[1]);
        fprintf(output, "===============================================\n\n");
    } else{
        printf("Error abriendo el archivo\n\n");
        printf("No se pudo imprimir las estadisticas\n\n");
    }
    fclose(output);
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

void quickSort(int* Arreglo, int longitud_arreglo, long long operaciones[]){
    
    int i = 0, j = longitud_arreglo - 1;
    int pivote = Arreglo[longitud_arreglo/2];
    
    if(longitud_arreglo < 2) return;

    for(;; i++, j--){
        
        while(Arreglo[i] < pivote){
            i++; operaciones[0]++;
        }
        while(Arreglo[j] > pivote){
            j--; operaciones[0]++;
        }

        if(i >= j) 
            break;
        else 
            operaciones[0] += 2; /*Hay dos comparaciones que no se contaron 
            pues no se entró en el bucle*/
        
        int fade = Arreglo[i];
        Arreglo[i] = Arreglo[j];
        Arreglo[j] = fade;
        operaciones[1]++;
    }

    quickSort(Arreglo, i, operaciones);
    quickSort(Arreglo + i, longitud_arreglo - i, operaciones);
}

void bubbleSort(int* Arreglo, int longitud_arreglo, long long operaciones[]){
    
     
    long float potencia = (pow(longitud_arreglo, 2) - longitud_arreglo)/2;
    operaciones[0] = (long long) potencia;
    operaciones[2] = longitud_arreglo - 1;

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

void selectionSort(int* Arreglo, int Longitud_arreglo, long long operaciones[]){

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

void bubbleSortFixed(int* Arreglo, int longitud_arreglo, long long operaciones[]){
    
    short order; //Variable booleana
    int it = 0; //Comparaciones,reposicionamientos e iteraciones
    
        for(int i = 1; i < longitud_arreglo; i++){
            order = 1; operaciones[2]++;
            for(int j = 0; j < longitud_arreglo - i; j++){
                operaciones[0]++;
                if(Arreglo[j] > Arreglo[j+1]){
                    short fade = Arreglo[j];
                    Arreglo[j] = Arreglo[j+1];
                    Arreglo[j+1] = fade;
                    order = 0;
                    operaciones[1]++;
                }
            }
            if(order) break;
        }
}

int buscarMenor ( int* Lista, int i, int N, long long* comparaciones){
    int menor = VALOR_MAYOR;
    int pos_menor;
    for ( ; i<N; i++ ){
        if (Lista[i] <= menor) {/*Inicialmente cualquier valor será menor que VALOR_MAYOR; así que 
        automáticamente el menor éstará en la posición i*/
            (*comparaciones)++;
            menor = Lista[i];
            pos_menor = i;
        }
        (*comparaciones)++; //Hay una condición no contada por que no se entra al if
    }
    return pos_menor;
}

void intercambiar ( int* Lista, int i, int pos_menor, long long* reposiciones){
    int a, b; //Evitan que se pierdan los valores originales
    
    a = Lista[i];
    b = Lista[pos_menor];

    Lista[i] = b;
    Lista[pos_menor] = a;
    (*reposiciones)++;
}