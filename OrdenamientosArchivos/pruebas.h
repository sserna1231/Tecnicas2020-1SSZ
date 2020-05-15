#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define VALOR_MAYOR 1000000
//Struct de las estadísticas
typedef struct Statistics_execution{
    char* fecha_init;
    char* fecha_fin;
    float exec_time;
    long long operaciones[3]; //Comparaciones, reposiciones, iteraciones
} stat;

//Este enum representa el orden de prueba con el tamanio del arreglo
enum Prueba{
FIRST = 10, SECOND = 100, THIRD = 1000, FOURTH = 10000,
FIFHT = 1245184
};

//Inicializa el menú de la prueba algoritmica
void menuPruebas(const char* Algoritmo);

//Realiza la prueba requerida para el tamaño de arreglo especificado por el enum
void realizarTestSorting(FILE *Archivo_input, int Test_size, short new_lines, const char* Algoritmo);

//Imprime las estadísticas de una prueba
void imprimirEstadisticas(stat *estadisticas_prueba, int Test_size, const char* Algoritmo_name);

//A partir de una posición i, recibe la posición del valor más pequeño e intercambia dichos valores
void intercambiar ( int* Lista, int i, int pos_menor, long long* reposiciones);

//A partir de una posición i busca en adelante cuál es el valor más pequeño en la lista, y regresa su posición {0...N-1}
int buscarMenor ( int* Lista, int i, int N, long long* comparaciones);

/*Devuelve una cadena con la fecha y hora exactas en el momento de su llamada,
en formato dd/mm/yyyy h/min/s*/
char* registroFecha(void);

//Algoritmo recursivo quicksort
void quickSort(int* Arreglo, int longitud_arreglo, long long operaciones[]);

//Algoritmo iterativo burbuja sencillo
void bubbleSort(int* Arreglo, int longitud_arreglo, long long operaciones[]);

//Algoritmo iterativoo de ordenamiento
void selectionSort(int* Arreglo, int Longitud_arreglo, long long operaciones[]);

//Algoritmo iterativo burbuja mejorado
void bubbleSortFixed(int* Arreglo, int longitud_arreglo, long long operaciones[]);