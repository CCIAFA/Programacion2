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

void cto_cargar_no_repetidos(Conjunto conjunto, int cantidad){
    TipoElemento clave;
    int i = 0;
    bool encontrado;
    if(cantidad<=10000){
      while (i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave: ");
        scanf("%d", &clave->clave);
        encontrado=cto_pertenece(conjunto,clave->clave);
        if(!encontrado){
            cto_agregar(conjunto, clave);
            i++;  
        }else{
            printf("no puede ingresar elementos repetidos\n");
        }
        
    }  
    }else{
        printf("no se puede cargar mas elementos que el tamaño maximo\n");
    }
    
}
