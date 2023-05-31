#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto4.h"
#include "valida.h"

int altura_int(NodoArbol n) {
    if (n == NULL) {
        return 0;
    }

    int altura_max = -1;
    NodoArbol hijo = n_hijoizquierdo(n);

    while (hijo != NULL) {
        int altura_hijo = altura_int(hijo);
        if (altura_hijo > altura_max) {
            altura_max = altura_hijo;
        }
        hijo = n_hijoderecho(hijo);
    }

    return altura_max + 1;
}

int an_altura(ArbolBinario a) {
    if (a_es_vacio(a)) {
        return -1;
    }

    return altura_int(a_raiz(a));
}

void nivel_int(NodoArbol nodo,int clave,int *h,int c){
    TipoElemento x;
    if(nodo!=NULL){
        x=n_recuperar(nodo);
        if(x->clave== clave){
            *h=c;
        }else{
            nivel_int(n_hijoizquierdo(nodo),clave,h,c+1);
            nivel_int(n_hijoderecho(nodo),clave,h,c);
        }
        
    }
}

int an_nivel(ArbolBinario a,int n){
    int nivel=-1;
    nivel_int(a_raiz(a),n,&nivel,0);
    return nivel;
}

void nodosint(NodoArbol nodo,Lista l,ArbolBinario a){
    TipoElemento x;
    int altura;
    bool primero=true;
    if(nodo==NULL){
    }else{
        if((n_hijoizquierdo(nodo)==NULL)||(a_raiz(a)==nodo)){ 
        }else{
            x=n_recuperar(nodo);
            l_agregar(l,x);  
        }
        nodosint(n_hijoizquierdo(nodo),l,a);
        nodosint(n_hijoderecho(nodo),l,a);
    }
    
}

Lista an_nodos_internos(ArbolBinario a){
    Lista l = l_crear();
    nodosint(a_raiz(a),l,a);
}

bool hojasAlMismoNivelint(NodoArbol nodo, int nivel, int *nivelHoja) {
    if (nodo == NULL)
        return true;

    // Si el nodo actual es una hoja
    if (nodo->hi == NULL) {
        // Si aún no se ha establecido el nivel de las hojas
        if (*nivelHoja == -1) {
            *nivelHoja = nivel;
        }
        // Si el nivel de las hojas es diferente al nivel actual
        else if (*nivelHoja != nivel) {
            return false;
        }
    }

    // Recorrer los hermanos del nodo actual
    NodoArbol hermano = nodo->hd;
    while (hermano != NULL) {
        if (!hojasAlMismoNivelint(hermano, nivel, nivelHoja)) {
            return false;
        }
        hermano = hermano->hd;
    }

    // Recorrer los hijos del nodo actual
    if (nodo->hi != NULL) {
        if (!hojasAlMismoNivelint(nodo->hi, nivel + 1, nivelHoja)) {
            return false;
        }
    }

    return true;
}
// Función principal para determinar si todas las hojas están al mismo nivel
bool an_hojasAlMismoNivel(NodoArbol raiz) {
    if (raiz == NULL)
        return true;

    int nivelHoja = -1;
    return hojasAlMismoNivelint(raiz, 0, &nivelHoja);
}

int main() {
    ArbolBinario a,a2;
    TipoElemento x;
    NodoArbol n;
    bool res;
    int i,clave;
    Lista lis;
    lis=l_crear();
    a=a_crear();
    cargar_arbol(a);
    i=an_altura(a);
    if(i==-1){
        printf("se ingreso un arbol vacio\n");
    }else{
        printf("la altura del arbol es: %d\n",i); 
    }
    
    ingresarNumero("\ningrese el nodo: ",&clave);
    i=an_nivel(a,clave);
    if(i==-1){
        printf("la clave no esta en el arbol\n");
    }else{
        printf("el nivel de la clave es %d\n",i);
    }
    lis=an_nodos_internos(a);
    l_mostrarLista(lis);
    res=an_hojasAlMismoNivel(a_raiz(a));
    if(res){
        printf("las hojas estan al mismo nivel\n");
    }else{printf("las hojas no estan al mismo nivel\n");}
}
