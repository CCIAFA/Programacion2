#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto5.h"
#include "valida.h"

void c_buscar_divisores(Cola cola) {
    Cola copia = c_crear();
    int longitud = c_longitud(cola);
    int divisor_total = -1; //asumimos que no hay divisor total
    int contador_parcial = 0;
    //Hacemos una copia de la cola para no modificar la original
    copia=c_duplicar(cola);
    
    //Comprobamos si cada elemento es divisor total o parcial
    while(!c_es_vacia(copia)) {
        TipoElemento divisor = c_desencolar(copia);
        int contador = 0;
        for(int i = 0; i < longitud; i++) {
            TipoElemento elemento = c_desencolar(cola);
            if(elemento->clave % divisor->clave == 0) {
                contador++;
            }
            c_encolar(cola, elemento);
        }
        if(contador == longitud) {
            divisor_total = divisor->clave;
        } else if(contador >= longitud/2) {
            printf("%d es divisor parcial\n", divisor->clave);
        }
    }
    if(divisor_total != -1) {
        printf("%d es divisor total\n", divisor_total);
    } else {
        printf("No hay divisor total\n");
    }
}

int main() {
    int clave,pos;
    Cola cola1;
    bool col,pil;
    cola1=c_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar_mayores_no_rep(cola1,clave,1);
    c_buscar_divisores(cola1);
    printf("cola original:\n");
    c_mostrar(cola1);
    printf("complejidad o(n^2)");   
       
}


