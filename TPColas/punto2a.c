#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2a.h"
#include "valida.h"

bool c_buscar_clave (Cola cola, int n){
	Cola Caux = c_crear();
	TipoElemento te;
	bool resultado = false;

    // ciclo que mueve los elementos a la cola auxiliar, similar a un p_intercambiar
	while (!c_es_vacia(cola)) {
		te = c_desencolar(cola);
		c_encolar(Caux, te);
    
		// condicional que se encontro el elemento buscado
		if (te->clave == n){
			resultado = true;
			break;
    	}
	}
	
	// recupero los elementos de la cola auxiliar a la original y la dejo como estaba
	c_intercambiar (cola, Caux);

	return resultado;    
}

int main() {
    int clave,elemento;
    Cola cola1;
    bool res;
    cola1=c_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);
    ingresarNumero("\ningrese el elemento a buscar: ",&clave);
    res=c_buscar_clave(cola1,clave);
    if(res){
        printf("el elemento esta en la cola");
    }else{
        printf("el elemento no se encuentra en la cola");
    }
   
    
}
