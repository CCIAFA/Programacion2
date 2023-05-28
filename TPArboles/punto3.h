#ifndef punto3_H
#define punto3_H
#include <stdbool.h>
#include "arbol-binario.h"
#include "utilidadesArboles.h"

void a_buscar_padre(ArbolBinario a, int clave);
void a_buscar_hijos(ArbolBinario a, int clave);
void a_buscar_hermano(ArbolBinario a, int clave);
int a_nivel(NodoArbol nodo, int clave);
void obtener_altura_rama(ArbolBinario a, int clave);
void listar_nodos_mismo_nivel(NodoArbol nodo, int nivel_actual, int nivel_deseado);
#endif 