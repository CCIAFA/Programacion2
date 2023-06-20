#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto7.h"
#include "valida.h"
#include "utilidadesConjuntos.h"

int cto_es_subconjunto(Conjunto conj1,Conjunto conj2){
    int i=1;
    int cont1=0;
    int res =-1;
    TipoElemento x;
    while(i<=cto_cantidad_elementos(conj1)){
        x=cto_recuperar(conj1,i);
        if(cto_pertenece(conj2,x->clave)){
            cont1++;
        }
        i++;
    }
    if(cont1==cto_cantidad_elementos(conj1)){
        res=1;
    }else if (cont1>=(cto_cantidad_elementos(conj2)/2)){
        res=2;
    }
    return res;
}

void cto_subcTP(Conjunto conj1,Conjunto conj2,Conjunto conj3){
    int i;
    int cont1=0;
    int cont2=0;
    TipoElemento x;
    //recorremos el conjunto A
    i=cto_es_subconjunto(conj1,conj2);
    if(i==1){
        printf("el conjunto A es un subconjunto total de B\n");
    }else if (i==2){
       printf("el conjunto A es un subconjunto parcial de B\n");     
    }
    
    i=cto_es_subconjunto(conj1,conj3);
    if(i==1){
        printf("el conjunto A es un subconjunto total de C\n");
    }else if (i==2){
       printf("el conjunto A es un subconjunto parcial de C\n");     
    }
    //recorremos el conjunto B
    i=cto_es_subconjunto(conj2,conj1);
    if(i==1){
        printf("el conjunto B es un subconjunto total de A\n");
    }else if (i==2){
       printf("el conjunto B es un subconjunto parcial de A\n");     
    }
    i=cto_es_subconjunto(conj2,conj3);
    if(i==1){
        printf("el conjunto B es un subconjunto total de C\n");
    }else if (i==2){
       printf("el conjunto B es un subconjunto parcial de C\n");     
    }    
    //recorremos el conjunto C
    i=cto_es_subconjunto(conj3,conj1);
    if(i==1){
        printf("el conjunto C es un subconjunto total de A\n");
    }else if (i==2){
       printf("el conjunto C es un subconjunto parcial de A\n");     
    }
    i=cto_es_subconjunto(conj3,conj2);
    if(i==1){
        printf("el conjunto C es un subconjunto total de B\n");
    }else if (i==2){
       printf("el conjunto C es un subconjunto parcial de B\n");     
    }    
    
}


int main(){
    Conjunto conj1,conj2,conj3;
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
    conj3= cto_crear();
    printf("\nconjunto C:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    cto_cargar_no_repetidos(conj3,clave);
    cto_subcTP(conj1,conj2,conj3);

    printf("complejidad o(n^2)");
}
