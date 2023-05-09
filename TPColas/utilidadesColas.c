#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void intercambiar(Cola cola,Cola Caux){
TipoElemento X;
while (c_es_vacia(Caux) != true) {
    X = c_desencolar(Caux);
    c_encolar(cola, X);
}
}

void c_cargar(Cola cola, int cantidad){
    TipoElemento clave;
    int i = 0;
    while (!c_es_llena(cola) && i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave a apilar: ");
        scanf("%d", &clave->clave);
        c_encolar(cola, clave);
        i++;
    }
}