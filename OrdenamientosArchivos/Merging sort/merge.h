# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define NULO 10000

//Regresa la matriz con nuevos valores en ella, recibe los datos explicados en main.cs
int** fasen ( int** Lista, int i, int N, int salto, int j1, int j2, int* pj3, int espacios1, int espacios2 );

//Reserva el espacio del arreglo en la memoria del computador 
int** reservarMemoria ( int n, int N );

//Regresa cuántos niveles se requieren para ordenar la lista de datos
int niveles ( int N );