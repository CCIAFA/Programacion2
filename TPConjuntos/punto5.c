#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto5.h"
#include "valida.h"
#include "utilidadesConjuntos.h"


Conjunto cto_diferencia_simetrica(Conjunto conj1,Conjunto conj2){
    int i;
    TipoElemento x;
    Conjunto conjres;
    conjres=cto_crear();
    i=1;
    while(i<=cto_cantidad_elementos(conj1)){
        x=cto_recuperar(conj1,i);
        if(!cto_pertenece(conj2,x->clave)){
            cto_agregar(conjres,x);
        }
        i++;
    }
    i=1;
    while(i<=cto_cantidad_elementos(conj2)){
        x=cto_recuperar(conj2,i);
        if(!cto_pertenece(conj1,x->clave)){
            cto_agregar(conjres,x);
        }
        i++;
    }

    return conjres;
}

int main(){
    Conjunto conj1,conj2,conj3;
    int clave;
    bool res;
    conj3=cto_crear();
    conj1= cto_crear();
    printf("conjunto 1:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar(conj1,clave);
    conj2= cto_crear();
    printf("\nconjunto 2:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar(conj2,clave);
    conj3=cto_diferencia_simetrica(conj1,conj2);
    printf("claves de la diferencia simetrica:\n");
    cto_mostrar(conj3);
}
