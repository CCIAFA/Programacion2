#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2c.h"
#include "utilidadesListas.h"
#include "valida.h"
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
    int clave;
    Lista l;
    a=a_crear();
    cargar_arbol(a); 
    ingresarNumero("\ningrese el numero que quiere ver las ocurrencias: ",&clave);
    l=a_buscar_ocurrencias(a,clave);
    printf("LISTADO DE NODOS :\n");
    l_mostrarTodo(l);
   printf("\ncomplejidad o(n)");
}
