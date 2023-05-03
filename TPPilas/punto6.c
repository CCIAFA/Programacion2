#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto6.h"
#include "utilidadesPilas.h"
#include "valida.h"


Pila eliminiarOcurrencias(Pila pila,int elemento){
TipoElemento x;
Pila paux, pres;
paux=p_crear();
pres=p_crear();
while(!p_es_vacia(pila)){
    x=p_desapilar(pila);
    p_apilar(paux,x);
    if(x->clave!=elemento){
        p_apilar(pres,x);
    }
}
p_intercambiar(pila,paux);
return pres;
}

int main(){
    Pila p,res;
    int clave;
    p=p_crear();
    res=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(p,clave);
    ingresarNumero("\ningrese el numero a eliminar: ",&clave);
    res=eliminiarOcurrencias(p,clave);
    printf("pila resultado\n");
    p_mostrar(res);
    printf("\npila original\n");
    p_mostrar(p);
}