#include "utilidadesConjuntos.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void cto_cargar(Conjunto Conjunto, int cantidad){
    TipoElemento clave;
    int i = 0;
	if(cantidad<=10000){
    	while (!cto_es_lleno(Conjunto) && i < cantidad) {
        	clave=te_crear(0);
        	printf("Ingrese la clave: ");
        	scanf("%d", &clave->clave);
        	cto_agregar(Conjunto, clave);
        	i++;
    	}
	}else{
		printf("no se puede cargar mas elementos que el tamaño maximo\n");
	}
}