#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "punto2a.h"
#include "valida.h"

bool buscar_clave (Pila pila, int n){
	Pila Paux = p_crear(Paux);
	TipoElemento te;
	bool resultado = false;

    // ciclo que mueve los elementos a la pila auxiliar, similar a un p_intercambiar
	while (!p_es_vacia(pila)) {
		te = p_desapilar(pila);
		p_apilar(Paux, te);
    
		// condicional que se encontro el elemento buscado
		if (te->clave == n){
			resultado = true;
			break;
    	}
	}
	
	// recupero los elementos de la pila auxiliar a la original y la dejo como estaba
	p_intercambiar (pila, Paux);

	return resultado;    
}

int main() {
    int clave;
    Pila pila1;
    bool encontrado;
    pila1=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila1,clave);
    ingresarNumero("\ningrese el elemento a buscar: ",&clave);
    encontrado= buscar_clave(pila1,clave);
    if(encontrado){
        printf("la clave se encuentra en la pila");
    }else{
        printf("la clave no se encuentra la pila");
    }
    
}
