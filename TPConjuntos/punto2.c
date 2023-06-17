#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2.h"
#include "valida.h"
#include "utilidadesConjuntos.h"
#include "Tipo_Elemento.c"
#include "validaciones.c"
#include "utilidadesConjuntos.c"
#include "conjuntos_avl.c"
#include "listas_arreglos.c"
#include "nodo.c"
#include "arbol-avl.c"

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

Conjunto ctoDiferencia(Conjunto conj1,Conjunto conj2){
    int i;
    Conjunto c3;
    TipoElemento x1;
    c3=cto_crear();
    if(cto_cantidad_elementos(conj1)!=0){
        for(i=1;i<=cto_cantidad_elementos(conj1);i++){
            x1=cto_recuperar(conj1,i);
            if(!cto_pertenece(conj2,x1->clave)){
                
                cto_agregar(c3,x1);
            }
        
        }
    }
    return c3;
}

bool ctoPertenece(Conjunto conj1,int c){
    int i;
    TipoElemento x;
    bool res= false;
    i=1;
    while(!res&&i<=cto_cantidad_elementos(conj1)){
        x=cto_recuperar(conj1,i);
        if(x->clave==c){
            res=true;
        }
        i++;
    }
    return res;
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
    conj3= ctoUniones(conj1,conj2);
    printf("\nunion\n");
    cto_mostrar(conj3);
    conj3= ctoInterseccion(conj1,conj2);
    printf("\ninterseccion\n");
    cto_mostrar(conj3);
    conj3= ctoDiferencia(conj1,conj2);
    printf("\ndiferencia\n");
    cto_mostrar(conj3);
    ingresarNumero("\ningrese un numero para ver si pertenece al conjunto: ",&clave);
    res=ctoPertenece(conj1,clave);
    if(res){
        printf("\nel numero petenece\n");
    }else{
        printf("\nel numero no petenece\n");
    }
}