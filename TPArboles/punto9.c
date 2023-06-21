#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto9.h"

void copiar_arbol_avl(NodoArbol nodo, ArbolAVL avl) {
    if (nodo == NULL) {
        return;
    }

    avl_insertar(avl, nodo->datos);
    copiar_arbol_avl(n_hijoizquierdo(nodo), avl);
    copiar_arbol_avl(n_hijoderecho(nodo), avl);
}

ArbolAVL cargar_avl(NodoArbol nodo) {
    ArbolAVL avl = avl_crear();

    copiar_arbol_avl(nodo, avl);

    return avl;
}

int main() {
    ArbolBinario a;
    NodoArbol n;
    ArbolAVL avl;
    int i,clave;
    a=a_crear();
    cargar_arbol(a);
    printf("inorder arbol binario:\n");
    in_orden(a_raiz(a));
    i=a_altura(a);
    printf("\nla altura del arbol binario es %d\n",i);
    avl=cargar_avl(a_raiz(a));
    printf("inorder arbol avl\n");
    in_orden(avl_raiz(avl));
    i=avl_altura(avl);
    printf("\nla altura del arbol avl es %d\n",i);
    printf("la complejidad es O(n log n) por el avl_insertar");
}
