#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto4.h"
#include "valida.h"

bool a_equivalente_int(NodoArbol nodo1, NodoArbol nodo2) {
    int x1,x2;
    if (nodo1 == NULL && nodo2 == NULL) {
        return true;
    }
    
    if (nodo1 == NULL || nodo2 == NULL) {
        return false;
    }
    
    if ((x1=n_recuperar(nodo1)->clave)!= (x2=n_recuperar(nodo2)->clave)) {
        return false;
    }
    
    bool hijosIguales = a_equivalente_int(n_hijoizquierdo(nodo1), n_hijoizquierdo(nodo2)) && a_equivalente_int(n_hijoderecho(nodo1), n_hijoderecho(nodo2));
    
    return hijosIguales;
}

bool a_equivalentes(ArbolBinario a1,ArbolBinario a2){
    bool res;
    res=a_equivalente_int(a_raiz(a1),a_raiz(a2));
    return res;
}


int main() {
    ArbolBinario a,a2;
    TipoElemento x;
    NodoArbol n;
    bool res;
    
    a=a_crear();
    a2=a_crear();
    printf("carga de arbol1:\n");
    cargar_arbol(a);
    printf("carga de arbol2:\n");
    cargar_arbol(a2);
res=a_equivalentes(a,a2);
if(res){printf("son equivalentes");}else{printf("no son eqivalentes");}

}
