#ifndef punto8_H
#define punto8_H
#include <stdbool.h>
#include "arbol-binario.h"
#include "utilidadesArboles.h"
#include "../TPListas/listas.h"

int an_altura(ArbolBinario a);
int an_nivel(ArbolBinario a,int n);
Lista an_nodos_internos(ArbolBinario a);
bool an_hojasAlMismoNivel(NodoArbol raiz);
#endif 