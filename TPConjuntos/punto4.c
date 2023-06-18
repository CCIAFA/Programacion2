#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto4.h"
#include "valida.h"
#include "utilidadesConjuntos.h"
#include "Tipo_Elemento.c"
#include "validaciones.c"
#include "utilidadesConjuntos.c"
#include "conjuntos_avl.c"
#include "listas_arreglos.c"
#include "nodo.c"
#include "arbol-avl.c"



bool ctoSubconjuntos(Conjunto conj1,Conjunto conj2,Conjunto conj3){
    bool subCab =true;
    bool subCbc=true;
    int i=1;
    TipoElemento x;
    while(subCab&&i<cto_cantidad_elementos(conj1)){
        x=cto_recuperar(conj1,i);
        if(!cto_pertenece(conj2,x->clave)){
            subCab=false;
        }
        i++;
    }
    i=1;
    while(subCbc&&i<cto_cantidad_elementos(conj2)){
        x=cto_recuperar(conj2,i);
        if(!cto_pertenece(conj3,x->clave)){
            subCbc=false;
        }
        i++;
    }
    if(subCab&&subCbc){
        return true;
    }else return false;
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
    printf("\nconjunto 3:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar(conj3,clave);
    res=ctoSubconjuntos(conj1,conj2,conj3);
    if(res){
        printf("a es subconjunto de b y b es subconjunto de c por lo tanto a es subconjunto de c");
    }else printf("la propieda de transitividad no se cumple");
}