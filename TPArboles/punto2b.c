#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2b.h"
#include "../TPListas/listas_arreglos.c"
#include "arbol-binario.c"
#include "Tipo_Elemento.c"
#include "nodo.c"
#include "utilidadesArboles.c"

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
    x=te_crear(10);
    a=a_crear();
    a_establecer_raiz(a,x);
    x=te_crear(20);
    n=a_conectar_hd(a,a_raiz(a),x);
    x=te_crear(25);
    a_conectar_hd(a,n,x);
    x=te_crear(5);
    n=a_conectar_hi(a,a_raiz(a),x);
    x=te_crear(1);
    a_conectar_hi(a,n,x);
    l=nodos(a);
    printf("LISTADO DE NODOS :\n");
    l_mostrarLista(l);
   printf("complejidad o(n)");
}