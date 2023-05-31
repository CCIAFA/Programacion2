#ifndef UTILIDADESA_H
#define UTILIDADESA_H
#include <stdbool.h>
#include "arbol-binario.h"
#include "arbol-avl.h"
#include "arbol-binario-busqueda.h"

void in_orden(NodoArbol N);
int a_altura(ArbolBinario a);
int avl_altura(ArbolAVL avl);
NodoArbol buscar_nodo(NodoArbol nodo, int clave);
void cargar_arbol(ArbolBinario a);

#endif 
