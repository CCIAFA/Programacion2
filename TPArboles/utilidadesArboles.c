#include "utilidadesArboles.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void in_orden(NodoArbol N){
    TipoElemento x;
    if(N==NULL){
        printf(".");
    }else{
        in_orden(n_hijoizquierdo(N));
        x=n_recuperar(N);
        printf("%d",x->clave);
        in_orden(n_hijoderecho(N));
    }
}


void alturaint(NodoArbol n,int *h,int c){
    if(n==NULL){
        if(c>*h){
            *h=c;
        }
    }else{
        alturaint(n_hijoizquierdo(n),h,c++);
        alturaint(n_hijoderecho(n),h,c++);
    }
}

int a_altura(ArbolBinario a){
    int alt =0;
    alturaint(a_raiz(a),&alt,0);
    return alt;
}
int avl_altura(ArbolAVL avl){
    int alt =0;
    alturaint(avl_raiz(avl),&alt,0);
    return alt;
}
int abb_altura(ArbolBinarioBusqueda abb){
    int alt =0;
    alturaint(abb_raiz(abb),&alt,0);
    return alt;
}
NodoArbol buscar_nodo(NodoArbol nodo, int clave) {
    if (nodo == NULL || nodo->datos->clave == clave) {
        return nodo;
    }
    
    // Buscar en el subárbol izquierdo
    NodoArbol nodo_izquierdo = buscar_nodo(nodo->hi, clave);
    if (nodo_izquierdo != NULL) {
        return nodo_izquierdo;
    }
    
    // Buscar en el subárbol derecho
    NodoArbol nodo_derecho = buscar_nodo(nodo->hd, clave);
    return nodo_derecho;
}

bool ingresarentero(int* dato) {
    char s[10];
    bool resultado =true;
    *dato=0;
    printf("ingrese una clave numerica o '.' para nulo: ");
    scanf("%s",s);
    if(s[0]=='.'){
        resultado=false;
    }else{
        for(int i=0;s[i]!='\0';i++){
            if((s[i]>='0')&&(s[i]<='9')){
                *dato=*dato * 10 + (s[i]-48);
            }
        }
    }
    return resultado;
}

void cargar_subarbol(ArbolBinario a,NodoArbol nodo,int sa){
    TipoElemento x;
    NodoArbol n1;
    int n;
    bool b;
    if(!a_es_lleno(a)){
        b=ingresarentero(&n);//agregar esta funcion despues
        if(b){
            x=te_crear(n);
            if(sa==-1)n1=a_conectar_hi(a,nodo,x);
            else if (sa==1) n1=a_conectar_hd(a,nodo,x);
            else n1=a_establecer_raiz(a,x);
            cargar_subarbol(a,n1,-1);
            cargar_subarbol(a,n1,1);
        }
    }
}

void cargar_arbol(ArbolBinario a){
    cargar_subarbol(a,NULL,0);
}


