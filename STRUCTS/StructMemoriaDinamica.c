#include "Structs.h"
#include "cadenas.h"

struct Fish * llenarFishMemDinamica(){
	//Se reserva el tamaño de lo que va a apuntar pFish
	fish_t * pFish = malloc(sizeof(fish_t));
	int i;

	if (pFish != NULL) {
		flush_in();
		printf("ingrese un nombre para el pez max 25 caracteres\n");
		fgets(pFish->nombre,25,stdin);
		printf("ingrese el numero de dientes \n");
		scanf("%d", &pFish->numDientes);
		printf("ingrese la edad del pez\n");
		scanf("%d", &pFish->edad);
		flush_in(); 
		printf("ingrese la especie para el pez max 20 caracteres\n");
		fgets(pFish->especie,20,stdin);

		//Reemplazo del new line caracter que inserta fgets
		for(i = 0; i <25; i++){
			if(pFish->nombre[i] == '\n')
				pFish->nombre[i] = 0;
			if(pFish->especie[i] == '\n')
				pFish->especie[i] = 0;
		}
		return pFish;
	}else{
		return NULL;
	}
}


void imprimirDatosPasoReferencia(fish_t* fish){
	
	printf("----------------\n");
	printf("Especie:%s \n", fish->especie);
	printf("Nombre pez:%s \n", fish->nombre);
	printf("Numero de dientes:%d \n", fish->numDientes);
	printf("Edad de especie:%d \n", fish->edad);
}
