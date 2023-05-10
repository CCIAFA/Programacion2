#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2c.h"
#include "valida.h"
#include "colas_punteros.c"
#include "utilidadesColas.c"
#include "Tipo_Elemento.c"
#include "validaciones.c"

void c_eliminar(Cola cola,int elemento){
    TipoElemento clave;
    Cola caux;
    caux=c_crear();
    while(!c_es_vacia(cola)){
        clave=c_desencolar(cola);
        if(clave->clave==elemento){
            //no se hace nada y se sigue desencolando
        }else{
            c_encolar(caux,clave);
        }
    }
    c_intercambiar(cola,caux);
}

int main() {
    int clave,posicion,elemento,longitud;
    Cola cola1;
    cola1=c_crear();
    
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);
    longitud=c_longitud(cola1);
    ingresarNumero("\ningrese el elemento a eliminar : ",&elemento);
    if(longitud==0){
        printf("la cola esta vacia");
    }else{
        c_eliminar(cola1,elemento);
        c_mostrar(cola1);  
    }
    
}