#ifndef UTILIDADESA_H
#define UTILIDADESA_H
#include <stdbool.h>
#include "arbol-binario.h"

void in_orden(NodoArbol N);
int a_altura(ArbolBinario a);
NodoArbol buscar_nodo(NodoArbol nodo, int clave);
void cargar_arbol(ArbolBinario a);

#endif 
