#ifndef punto4_H
#define punto4_H
#include <stdbool.h>
#include "arbol-binario.h"
#include "utilidadesArboles.h"
#include "../TPListas/listas.h"
#include "../TPColas/colas.h"

int an_hojas(ArbolBinario a);
NodoArbol an_padre(ArbolBinario a, int clave);
Lista an_hermanos(ArbolBinario a, int clave);
bool a_similar(ArbolBinario a1,ArbolBinario a2);
Lista an_anchura(ArbolBinario a);

#endif 