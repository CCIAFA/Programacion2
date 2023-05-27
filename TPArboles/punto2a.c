#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2a.h"



void hojasint(NodoArbol nodo,Lista l){
    TipoElemento x;
    if(nodo==NULL){
    }else{
        if((n_hijoderecho(nodo)==NULL)&&(n_hijoizquierdo(nodo)==NULL)){
            x=n_recuperar(nodo);
            l_agregar(l,x);
            //printf("%d",x->clave);
        }
        hojasint(n_hijoizquierdo(nodo),l);
        hojasint(n_hijoderecho(nodo),l);
    }
    
}

Lista hojas(ArbolBinario a){
    Lista l = l_crear();
    hojasint(a_raiz(a),l);
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
    x=te_crear(5);
    n=a_conectar_hi(a,a_raiz(a),x);
    l=hojas(a);
    printf("LISTADO DE HOJAS:\n");
    l_mostrarLista(l);
   printf("complejidad o(n)");
}
