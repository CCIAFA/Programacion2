#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "punto2a.h"

bool buscar_clave (Pila pila, int n){
	Pila Paux = p_crear(Paux);
	TipoElemento te;
	resultado = False;

    // ciclo que mueve los elementos a la pila auxiliar, similar a un p_intercambiar
	while (!p_es_vacia(pila)) {
	te = p_desapilar(pila);
	p_apilar(Paux, te);
	}
    
	// condicional que se encontro el elemento buscado
	if (te->clave == n){
		resultado = True;
		break;
    }
	
	// recupero los elementos de la pila auxiliar a la original y la dejo como estaba
	p_intercambiar (Pila pila, Pila Paux);

	return resultado;    
}
