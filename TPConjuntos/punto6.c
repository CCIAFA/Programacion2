#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto6.h"
#include "valida.h"
#include "utilidadesConjuntos.h"
#include "Tipo_Elemento.c"
#include "validaciones.c"
#include "utilidadesConjuntos.c"
#include "conjuntos_avl.c"
#include "listas_arreglos.c"
#include "nodo.c"
#include "arbol-avl.c"

bool cto_subconjuntos(Conjunto conj1,Conjunto conj2){
    bool res=true;
    int i=1;
    TipoElemento x;
    while(res&&i<=cto_cantidad_elementos(conj1)){
        x=cto_recuperar(conj1,i);
        if(!cto_pertenece(conj2,x->clave)){
            res=false;
        }
        i++;
    }
    return res;
}

int main(){
    Conjunto conj1,conj2;
    int clave;
    bool res;
    conj1= cto_crear();
    printf("conjunto A:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar(conj1,clave);
    conj2= cto_crear();
    printf("\nconjunto B:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar(conj2,clave);
    if(cto_cantidad_elementos(conj1)<cto_cantidad_elementos(conj2)){
        res=cto_subconjuntos(conj1,conj2);
        if(res){
            printf("el conjunto A es subconjunto de B\n");
        }else printf("ninguno es subconjunto del otro\n"); 
    }else if (cto_cantidad_elementos(conj2)<cto_cantidad_elementos(conj1)){
        res=cto_subconjuntos(conj2,conj1);
        if(res){
            printf("el conjunto B es subconjunto de A\n");
        }else printf("ninguno es subconjunto del otro\n");
    }else{
        res=cto_subconjuntos(conj1,conj2);
        if(res){
            printf("ambos son subconjuntos entre si\n");
        }else{printf("ninguno es subconjunto del otro\n");}
    }
    
    
}