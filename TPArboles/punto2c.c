#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2c.h"
#include "utilidadesListas.h"
#include "../TPListas/listas_arreglos.c"
#include "arbol-binario.c"
#include "Tipo_Elemento.c"
#include "nodo.c"
#include "utilidadesArboles.c"
#include "../TPListas/utilidadesListas.c"
void buscar_ocurrencias_int(NodoArbol nodo, int clave, Lista ocurrencias) {
    TipoElemento x;
    if (nodo == NULL) {
        return;
    }

    TipoElemento datos = n_recuperar(nodo);
    int nodo_clave = datos->clave;

    if (nodo_clave == clave) {
        x=te_crear_con_valor(nodo->datos->clave,nodo);
        l_agregar(ocurrencias,x);
    }

    buscar_ocurrencias_int(n_hijoizquierdo(nodo), clave, ocurrencias);
    buscar_ocurrencias_int(n_hijoderecho(nodo), clave, ocurrencias);
}

Lista a_buscar_ocurrencias(ArbolBinario a, int clave) {
    Lista ocurrencias = l_crear();
    buscar_ocurrencias_int(a_raiz(a), clave, ocurrencias);
    return ocurrencias;
}

int main() {
    ArbolBinario a;
    TipoElemento x;
    NodoArbol n;
    Lista l;
    x=te_crear(10);
    a=a_crear();
    a_establecer_raiz(a,x);
    x=te_crear(20);
    n=a_conectar_hd(a,a_raiz(a),x);
    x=te_crear(25);
    a_conectar_hd(a,n,x);
    x=te_crear(20);
    n=a_conectar_hi(a,a_raiz(a),x);
    x=te_crear(1);
    a_conectar_hi(a,n,x);
    l=a_buscar_ocurrencias(a,20);
    printf("LISTADO DE NODOS :\n");
    l_mostrarTodo(l);
   printf("\ncomplejidad o(n)");
}