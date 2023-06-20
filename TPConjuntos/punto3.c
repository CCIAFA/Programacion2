#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto3.h"
#include "valida.h"
#include "utilidadesConjuntos.h"

Conjunto ctoUniones(Conjunto conj1,Conjunto conj2){
    int i,j;
    Conjunto c3;
    TipoElemento x1,x2;
    c3=cto_crear();
    if(cto_cantidad_elementos(conj1)!=0){
        for(i=1;i<=cto_cantidad_elementos(conj1);i++){
        x1=cto_recuperar(conj1,i);
        cto_agregar(c3,x1);
        }
    }
    if(cto_cantidad_elementos(conj2)!=0){
        for(j=1;j<=cto_cantidad_elementos(conj2);j++){
       
            x2=cto_recuperar(conj2,j);
            cto_agregar(c3,x2);
        }
    }
    return c3;
}

Conjunto ctoInterseccion(Conjunto conj1,Conjunto conj2){
    int i;
    Conjunto c3;
    TipoElemento x1;
    c3=cto_crear();
    if(cto_cantidad_elementos(conj1)!=0){
        for(i=1;i<=cto_cantidad_elementos(conj1);i++){
            x1=cto_recuperar(conj1,i);
            if(cto_pertenece(conj2,x1->clave)){
                
                cto_agregar(c3,x1);
            }
        
        }
    }
    return c3;
}

int main(){
    Conjunto conj1,conj2,conj3;
    int clave;
    conj3=cto_crear();
    conj1= cto_crear();
    printf("conjunto 1:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar_no_repetidos(conj1,clave);
    conj2= cto_crear();
    printf("\nconjunto 2:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar_no_repetidos(conj2,clave);
    conj3= ctoUniones(conj1,conj2);
    printf("\nunion\n");
    cto_mostrar(conj3);
    conj3= ctoInterseccion(conj1,conj2);
    printf("\ninterseccion\n");
    cto_mostrar(conj3);
}