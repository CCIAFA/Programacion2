#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto4.h"
#include "valida.h"
#include "arbol-binario.c"
#include "Tipo_Elemento.c"
#include "nodo.c"
#include "utilidadesArboles.c"
#include "validaciones.c"
#include "../TPListas/utilidadesListas.c"
#include "../TPListas/listas_arreglos.c"
#include "../TPColas/colas_punteros.c"

void hojasint(NodoArbol nodo,int *cont){
    TipoElemento x;
    
    if(nodo==NULL){
    }else{
        if(n_hijoizquierdo(nodo)==NULL){
            x=n_recuperar(nodo);
            (*cont)++;
            //printf("%d",x->clave);
        }
        hojasint(n_hijoizquierdo(nodo),cont);
        hojasint(n_hijoderecho(nodo),cont);
    }
    
}

int an_hojas(ArbolBinario a){
    int contador=0;
    if((n_hijoderecho(a_raiz(a))==NULL)&&(n_hijoizquierdo(a_raiz(a))==NULL)){
        return 0;
    }else{
        hojasint(a_raiz(a),&contador);
        return contador;  
    }
    
}


void nodoPadreInt(ArbolBinario a, NodoArbol nodoActual, NodoArbol padre, int clave, NodoArbol* resultado) {
    if (nodoActual != NULL) {
        NodoArbol hijo = n_hijoizquierdo(nodoActual);
        while (hijo != NULL) {
            if (n_recuperar(hijo)->clave == clave) {
                *resultado = nodoActual;
                return;
            }
            hijo = n_hijoderecho(hijo);
        }
        
        nodoPadreInt(a, n_hijoizquierdo(nodoActual), nodoActual, clave, resultado);
        nodoPadreInt(a, n_hijoderecho(nodoActual), padre, clave, resultado);
    }
}

NodoArbol an_padre(ArbolBinario a, int clave) {
    NodoArbol resultado = NULL;
    if((n_hijoderecho(a_raiz(a))==NULL)&&(n_hijoizquierdo(a_raiz(a))==NULL)){
        return NULL;
    }else{
        nodoPadreInt(a, a_raiz(a), NULL, clave, &resultado);
        return resultado;
    }
    
}

void nodos_hermanosint(NodoArbol padre, NodoArbol actual, int clave, Lista l) {
    if (padre == NULL) {
        return;
    }
    
    actual = n_hijoizquierdo(padre);
    while (actual != NULL) {
        if (n_recuperar(actual)->clave != clave) {
            l_agregar(l, n_recuperar(actual));
        }
        actual = n_hijoderecho(actual);
    }
    
    nodos_hermanosint(n_hijoderecho(padre), NULL, clave, l);
}

Lista an_hermanos(ArbolBinario a, int clave) {
    Lista l = l_crear();
    NodoArbol padre = an_padre(a, clave);
    if (padre != NULL) {
        nodos_hermanosint(padre, NULL, clave, l);
    }
    return l;
}

bool a_equivalente_int(NodoArbol nodo1, NodoArbol nodo2) {
    int x1,x2;
    if (nodo1 == NULL && nodo2 == NULL) {
        return true;
    }
    
    if (nodo1 == NULL || nodo2 == NULL) {
        return false;
    }
    
   
    bool hijosIguales = a_equivalente_int(n_hijoizquierdo(nodo1), n_hijoizquierdo(nodo2)) && a_equivalente_int(n_hijoderecho(nodo1), n_hijoderecho(nodo2));
    
    return hijosIguales;
}

bool a_similar(ArbolBinario a1,ArbolBinario a2){
    bool res;
    res=a_equivalente_int(a_raiz(a1),a_raiz(a2));
    return res;
}

Lista an_anchura(ArbolBinario a) {
    Cola c;
    NodoArbol n;
    TipoElemento x;
    Lista l=l_crear();
    if (!a_es_vacio(a)) {
        c = c_crear();
        n = a_raiz(a);
        x = te_crear_con_valor(0, n);
        c_encolar(c, x);
        
        while (!c_es_vacia(c)) {
            x = c_desencolar(c);
            n = (NodoArbol)x->valor;
            printf("%d ", n_recuperar(n)->clave);
            l_agregar(l,n->datos);
            // Enqueue los hijos (nodos izquierdos) del nodo actual
            NodoArbol hijo = n_hijoizquierdo(n);
            while (hijo != NULL) {
                x = te_crear_con_valor(0, hijo);
                c_encolar(c, x);
                hijo = n_hijoderecho(hijo);
            }
        }
    }
}

int main() {
    ArbolBinario a,a2;
    TipoElemento x;
    NodoArbol n;
    int cont,clave,i;
    bool res;

    Lista lis,lis2;
    a=a_crear();
    a2=a_crear();
    printf("carga de arbol1:\n");
    cargar_arbol(a);
    printf("carga de arbol2:\n");
    cargar_arbol(a2);
    lis=l_crear();
    lis2=l_crear();
    ingresarNumero("\ningrese el nodo: ",&clave);
    cont=an_hojas(a);
    printf("cantidad de hojas: %d\n",cont);
    i=an_altura(a);
    printf("la altura es: %d\n",i);
    n=an_padre(a,clave);
    if(n!=NULL){
        printf("el padre es %d\n",n_recuperar(n)->clave);  
    }
    lis=an_hermanos(a,clave);
    l_mostrarLista(lis);
    res=a_similar(a,a2);
    if(res){
        printf("son similares\n");
    }else{
        printf("no son similares\n");
    }
    lis2=an_anchura(a);
    printf("se muestra la anchura\n");
    l_mostrarLista(lis2);
}