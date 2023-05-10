#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2e.h"
#include "valida.h"
#include "colas_punteros.c"
#include "utilidadesColas.c"
#include "Tipo_Elemento.c"
#include "validaciones.c"

Cola c_duplicar(Cola cola){
    TipoElemento clave;
    int longitud;
    longitud=c_longitud(cola);
    Cola caux ,caux2;
    caux=c_crear();
    caux2=c_crear();
    while(!c_es_vacia(cola)){
        clave=c_desencolar(cola);
        c_encolar(caux,clave);
        c_encolar(caux2,clave);
    }
    c_intercambiar(cola,caux);
    c_intercambiar(caux,caux2);
    return caux;
}


int main() {
    int clave,posicion,elemento,longitud;
    Cola cola1,cres;
    cola1=c_crear();
    cres=c_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);

    cres=c_duplicar(cola1);
    printf("cola original:\n");
    c_mostrar(cola1);
    printf("cola duplicada:\n");
    c_mostrar(cres);
   
    
}