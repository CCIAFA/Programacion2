#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2b.h"
#include "utilidadesArboles.h"

void nodosint(NodoArbol nodo,Lista l,ArbolBinario a){
    TipoElemento x;
    int altura;
    bool primero=true;
    if(nodo==NULL){
    }else{
        if((n_hijoderecho(nodo)==NULL)&&(n_hijoizquierdo(nodo)==NULL)||(a_raiz(a)==nodo)){ 
        }else{
            x=n_recuperar(nodo);
            l_agregar(l,x);  
        }
        nodosint(n_hijoizquierdo(nodo),l,a);
        nodosint(n_hijoderecho(nodo),l,a);
    }
    
}

Lista nodos(ArbolBinario a){
    Lista l = l_crear();
    nodosint(a_raiz(a),l,a);
}

int main() {
    ArbolBinario a;
    TipoElemento x;
    NodoArbol n;
    Lista l;

    a=a_crear();
    a=a_crear();
    l=nodos(a);
    printf("LISTADO DE NODOS :\n");
    l_mostrarLista(l);
   printf("complejidad o(n)");
}
