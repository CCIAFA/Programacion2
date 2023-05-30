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
    x=te_crear(10);
    a=a_crear();
    a_establecer_raiz(a,x);
    x=te_crear(20);
    n=a_conectar_hi(a,a_raiz(a),x);
    x=te_crear(25);
    a_conectar_hd(a,n,x);
    x=te_crear(5);
    n=a_conectar_hi(a,n,x);
    
    x=te_crear(10);
    a2=a_crear();
    a_establecer_raiz(a2,x);
    x=te_crear(20);
    n=a_conectar_hi(a2,a_raiz(a2),x);
    x=te_crear(25);
    a_conectar_hd(a2,n,x);
    x=te_crear(5);
    n=a_conectar_hi(a2,n,x);

res=a_equivalentes(a,a2);
if(res){printf("son equivalentes");}else{printf("no son eqivalentes");}

}