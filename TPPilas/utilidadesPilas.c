#include "utilidadesPilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//pone el contenido de la pila auxiliar devuelta en la pila original
void p_intercambiar(Pila pila,Pila Paux){
    TipoElemento X=te_crear(0);
    while (p_es_vacia(Paux) != true) {
    X = p_desapilar(Paux);
    p_apilar(pila, X);
}
};
//recibe la pila y la cantida de elementos que se quieran ingresars
void p_cargar(Pila pila, int cantidad){
    TipoElemento clave;
    int i = 0;
    while (!p_es_llena(pila) && i < cantidad) {
        printf("Ingrese la clave a apilar: ");
        scanf("%d", &clave->clave);
        p_apilar(pila, clave);
        i++;
    }
}