#include "Structs.h"

int main()
{
	
	struct Fish pirana1 = {"Snappy", "Piranha", 69, 4};
	struct Fish arregloPiranitas[5];
	struct Fish pirana2;
	
	pirana2 = llenarFishTypeDef();
	imprimirDatosPasoValor(pirana1);
	imprimirDatosPasoValor(pirana2);
	
	//TODO: Llamar a imprimir usando la función del paso por valor
	//Pruebas paso por referencia y memoria dinámica
	// Equivalente a decir fish_t *pFish= (fish_t*) llenarFishMemDinamica();
	fish_t * pFish = (fish_t *) llenarFishMemDinamica();

	//TODO: Llamar a imprimir usando la función del paso por referencia
	//Imprimir usando la función para paso por referencia
	imprimirDatosPasoReferencia(pFish);
	
	//Se libera la memoria de pFIsh
	free(pFish);
	system("PAUSE");
	return 0;
}
