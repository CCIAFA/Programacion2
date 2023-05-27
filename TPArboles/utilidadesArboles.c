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

