#include "utilidadesPilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//pone el contenido de la pila auxiliar devuelta en la pila original
void p_intercambiar(Pila pila,Pila Paux){
    TipoElemento X=te_crear(0);
    while (p_es_vacia(Paux) != true) {
    X = p_desapilar(Paux);
    p_apilar(pila, X);
}
};
//recibe la pila y la cantida de elementos que se quieran ingresars
void p_cargar(Pila pila, int cantidad){
    TipoElemento clave;
    int i = 0;
    while (!p_es_llena(pila) && i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave a apilar: ");
        scanf("%d", &clave->clave);
        p_apilar(pila, clave);
        i++;
    }
}

bool p_buscar_clave (Pila pila, int n){
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
