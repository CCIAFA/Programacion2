#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void intercambiar(Cola cola,Cola Caux){
TipoElemento X;
while (c_es_vacia(Caux) != true) {
    X = c_desencolar(Caux);
    c_encolar(cola, X);
}
}

void c_cargar(Cola cola, int cantidad){
    TipoElemento clave;
    int i = 0;
    while (!c_es_llena(cola) && i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave a encolar: ");
        scanf("%d", &clave->clave);
        c_encolar(cola, clave);
        i++;
    }
}

int c_longitud(Cola cola){
int i;
Cola caux;
caux=c_crear();
i=0;
TipoElemento x;
while(!c_es_vacia(cola)){
	x=c_desencolar(cola);
	c_encolar(caux,x);
	i=i+1;
}
c_intercambiar(cola,caux);
return i;
}

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
