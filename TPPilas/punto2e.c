#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2e.h"
#include "utilidadesPilas.h"
#include "valida.h"


Pila p_duplicar(Pila pila){
    TipoElemento clave;
    int longitud;
    longitud=p_longitud(pila);
    Pila paux ,paux2;
    paux=p_crear();
    paux2=p_crear();
    while(!p_es_vacia(pila)){
        clave=p_desapilar(pila);
        p_apilar(paux,clave);
        p_apilar(paux2,clave);
    }
    p_intercambiar(pila,paux);
    p_intercambiar(paux,paux2);
    return paux;
}


int main() {
    int clave,posicion,elemento,longitud;
    Pila pila1,pres;
    pila1=p_crear();
    pres=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila1,clave);

    pres=p_duplicar(pila1);
    printf("pila original:\n");
    p_mostrar(pila1);
    printf("pila duplicada:\n");
    p_mostrar(pres);
   
    
}
