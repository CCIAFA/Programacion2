#include "pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 20;
struct Nodo {
TipoElemento datos; // Concepto del Nodo
struct Nodo *siguiente;
};
struct PilaRep {
struct Nodo *tope;
};

Pila p_crear() {
Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
nueva_pila->tope = NULL;
return nueva_pila;
}
void p_apilar (Pila pila, TipoElemento elemento) {
struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
if (p_es_llena(pila)) {
        return;
    }
nuevo_nodo->datos = elemento;
nuevo_nodo->siguiente = pila->tope;
pila->tope = nuevo_nodo;
}

TipoElemento p_desapilar (Pila pila) {
if (p_es_vacia(pila)) {
        return NULL;
    }    
struct Nodo *tope_actual = pila->tope;
TipoElemento elemento = tope_actual->datos;
pila->tope = tope_actual->siguiente;
free(tope_actual);
return elemento;
}

TipoElemento p_tope (Pila pila) {
if (p_es_vacia(pila)) {
        return NULL;
    }       
struct Nodo *tope_actual = pila->tope;
return tope_actual->datos;
}

int longitud(Pila pila){
    int i =0;
    struct Nodo *N=pila->tope;
    while(N!=NULL){
        i++;
        N =N->siguiente;
    }
    return i;
}

bool p_es_llena (Pila pila) {
return(longitud(pila)==TAMANIO_MAXIMO);    
}

bool p_es_vacia (Pila pila) {
return pila->tope == NULL;
}

void p_mostrar (Pila pila) {

if(p_es_vacia(pila)){
        printf("PILA VACIA \n");
        return;
    }

Pila Paux = p_crear();
TipoElemento X = te_crear(0);
printf("Contenido de la pila: ");
// Recorro la pila desopilándola y pasándola al auxiliar
while (p_es_vacia(pila) != true) {
X = p_desapilar(pila);
printf("%d ", X->clave);
p_apilar(Paux, X);
}
// Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
while (p_es_vacia(Paux) != true) {
X = p_desapilar(Paux);
p_apilar(pila, X);
}
printf("\n");
}
