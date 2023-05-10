#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2b.h"
#include "valida.h"


Cola c_insertar(Cola cola, int pos, int x) {
    TipoElemento clave;
    int i = 1;
    int longitud = c_longitud(cola);
    Cola caux = c_crear();

    while (!c_es_vacia(cola) && i <= longitud) {
        if (pos == longitud + 1) { // si se quiere insertar en la última posición se encola directamente y termina el programa
            clave = te_crear(x);
            c_encolar(cola, clave);
            break;
        } else if (i == pos) { // si i es igual a la posición se inserta el elemento en la cola
            clave = te_crear(x);
            c_encolar(caux, clave);
        }

        // desencolar y volver a encolar en la cola auxiliar
        TipoElemento elemento = c_desencolar(cola);
        c_encolar(caux, elemento);

        i = i + 1;
    }

    // se intercambia la cola original con la cola auxiliar
    c_intercambiar(cola, caux);

    if(c_es_vacia(cola)){//si viene una cola vacia se inserta el elemento
        clave=te_crear(x);
        c_encolar(cola,clave); 
    }

    return cola;
}


int main() {
    int clave,posicion,elemento,longitud;
    Cola cola1,cres;
    cola1=c_crear();
    cres=c_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);
    longitud=c_longitud(cola1);
    ingresarNumero("\ningrese la posicion a insertar : ",&posicion);
    ingresarNumero("\ningrese el elemento a insertar : ",&elemento);
    if(posicion >longitud+1){
        printf("no se puede insertar en la posicion dada");
    }else{
        cres=c_insertar(cola1,posicion,elemento);
        c_mostrar(cres);  
    }
    
}




