#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2d.h"
#include "utilidadesPilas.h"
#include "valida.h"


Pila p_intercambio(Pila pila, int pos1, int pos2) {
    int i = 1;
    Pila paux = p_crear();
    TipoElemento temp1 = NULL;
    TipoElemento temp2 = NULL;
    TipoElemento x;
    
    while (i < pos1 && !p_es_vacia(pila)) {
        x=p_desapilar(pila);
        p_apilar(paux, x);
        i++;
    }

    
    if (i == pos1 && !p_es_vacia(pila)) {
        temp1 = p_desapilar(pila);
    }

    i = 1;
    
    while (i < pos2 && !p_es_vacia(pila)){
        x=p_desapilar(pila);
        p_apilar(paux, x);
        i++;
    }

  
    if (i == pos2 && !p_es_vacia(pila)) {
        temp2 = p_desapilar(pila);
    }

    if (temp1 != NULL) {
        p_apilar(pila, temp1);
    }

    while (!p_es_vacia(paux)) {
        p_apilar(pila, p_desapilar(paux));
    }

    if (temp2 != NULL) {
        p_apilar(pila, temp2);
    }

    return pila;
}
int main() {
    int clave,posicion,elemento,longitud;
    Pila pila1,pres;
    pila1=p_crear();
    pres=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila1,clave);
    longitud=p_longitud(pila1);
    ingresarNumero("\ningrese la primera posicion a intercambiar : ",&posicion);
    ingresarNumero("\ningrese la segunda posicion a intercambiar : ",&elemento);
    if(posicion >longitud){
        printf("no se puede insertar en la posicion dada");
    }else{
        pres=p_intercambio(pila1,posicion,elemento);
        p_mostrar(pres);  
    }
    
}