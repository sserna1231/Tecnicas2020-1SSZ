#include "Structs.h"
#include "Cadenas.h"

struct Fish llenarFishMemEstatica(){
	
	struct Fish fish;
	int i;

	printf("ingrese un nombre para el pez max 25 caracteres\n");
	fgets(fish.nombre,25,stdin);
	printf("ingrese el numero de dientes \n");
	scanf("%d", &fish.numDientes);
	printf("ingrese la edad del pez\n");
	scanf("%d", &fish.edad);
	flush_in(); 
	printf("ingrese la especie para el pez max 25 caracteres\n");
	fgets(fish.especie,25,stdin);

	//Reemplazo de los \n caracteres que inserta fgets
	for(i = 0; i <25; i++){
		if(fish.nombre[i] == '\n')
			fish.nombre[i] = 0;
		if(fish.especie[i] == '\n')
			fish.especie[i] = 0;
	}
	return fish;
}

fish_t llenarFishTypeDef(){
	/* La lógica es igual, la diferencia es que 
	la declaración de la variable se hace con fish_t*/
	int i;
	fish_t fish;
	
	printf("ingrese un nombre para"
		" el pez max 25 caracteres\n");
	fgets(fish.nombre,25,stdin);
	printf("ingrese la especie para el pez max 20 caracteres\n");
	fgets(fish.especie, 20, stdin);
	printf("ingrese el numero de dientes \n");
	scanf("%d", &fish.numDientes);
	printf("ingrese la edad del pez\n");
	scanf("%d", &fish.edad);
	//Reemplazo del new line caracter que inserta fgets
	for(i = 0; i <25; i++){
		if(fish.nombre[i] == '\n')
			fish.nombre[i] = 0;
		if(fish.especie[i] == '\n')
			fish.especie[i] = 0;
	}
	return fish;
}

/* Se recibe la direccion de la estructura y no su valor para impresion*/
void imprimirDatosPasoValor(fish_t fish){
	printf("----------------\n");
	printf("Especie:%s \n", fish.especie);
	printf("Nombre pez:%s \n", fish.nombre);
	printf("Numero de dientes:%d \n", fish.numDientes);
	printf("Edad de especie:%d \n", fish.edad);
}
