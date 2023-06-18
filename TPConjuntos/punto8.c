#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto8.h"
#include "valida.h"
#include "utilidadesConjuntos.h"

bool cto_son_iguales(Conjunto conj1,Conjunto conj2){
    bool res=true;
    int i=1;
    TipoElemento x;
    if(cto_cantidad_elementos(conj1)==cto_cantidad_elementos(conj2)){
        while(res&&i<=cto_cantidad_elementos(conj1)){
            x=cto_recuperar(conj1,i);
        if(!cto_pertenece(conj2,x->clave)){
            res=false;
        }
        i++;
        }
        return res;
    }else return false;
}

int main(){
    Conjunto conj1,conj2;
    int clave;
    bool res;
    conj1= cto_crear();
    printf("conjunto A:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar_no_repetidos(conj1,clave);
    conj2= cto_crear();
    printf("\nconjunto B:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar_no_repetidos(conj2,clave);
    res=cto_son_iguales(conj1,conj2);
    if(res){
        printf("los conjuntos son iguales");
    }else printf("los conjuntos son distintos");
    printf("complejidad o(n^2)");
}
