# include <stdio.h>
# include <stdlib.h>
#include <time.h>
# define VALOR_MAYOR 1000000; //Este número jamás será ingresado por el usuario

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

//Algoritmo iterativoo de ordenamiento
void selectionSort(int* Arreglo, int Longitud_arreglo, int operaciones[]);

//Regresa la matriz con su espacio reservado en la memoria del computador
int* reservarMemoria ( int N );

//Solicita los elemtos de la lista de tamaño N al usuario
void llenarMatriz ( int* Lista, int N );

//A partir de una posición i busca en adelante cuál es el valor más pequeño en la lista, y regresa su posición {0...N-1}
int buscarMenor ( int* Lista, int i, int N, int* comparaciones);

//A partir de una posición i, recibe la posición del valor más pequeño e intercambia dichos valores
void intercambiar ( int* Lista, int i, int pos_menor, int* reposiciones);

//Imprime la matriz una vez organizada de menor a mayor
void imprimirMatriz ( int* Lista, int N );

//Realiza la prueba requerida para el tamaño de arreglo especificado por el enum
void realizarTestSorting(FILE *Archivo_input, short Test_size, short new_lines);

//Imprime las estadísticas de una prueba
void imprimirEstadisticas(stat *estadisticas_prueba, int Test_size, char* Algoritmo_name);

/*Devuelve una cadena con la fecha y hora exactas en el momento de su llamada,
en formato dd/mm/yyyy h/min/s*/
char* registroFecha(void);