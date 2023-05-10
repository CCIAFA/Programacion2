#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2f.h"
#include "valida.h"
#include "colas_punteros.c"
#include "utilidadesColas.c"
#include "Tipo_Elemento.c"
#include "validaciones.c"


bool c_son_iguales(Cola c1,Cola c2){
    TipoElemento clave1,clave2;
    Cola caux;
    bool bandera=true;
    caux=c_crear();
    while (!c_es_vacia(c1)){
        clave1=c_desencolar(c1);
        clave2=c_desencolar(c2);
        c_encolar(caux,clave1);
        c_encolar(c2,clave2);
        if(clave1->clave!=clave2->clave){
            bandera=false;
        }

    }
    c_intercambiar(c1,caux);
    return bandera;
}

int main() {
    int clave,longitud1,longitud2;
    Cola cola1,cola2;
    bool sonIguales;
    cola1=c_crear();
    cola2=c_crear();
    printf("cola1\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);
    printf("cola2\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola2,clave);
    longitud1=c_longitud(cola1);
    longitud2=c_longitud(cola2);
    if(longitud1==longitud2){
       sonIguales=c_son_iguales(cola1,cola2);
        if(sonIguales){
            printf("------las colas son iguales--------\n");
        }else{
            printf("-------las colas son distintas-------\n");
        }
    }else{
       printf("las colas son distintas\n"); 
    }
    
    
    printf("cola 1\n");
    c_mostrar(cola1);
    printf("cola 2\n");
    c_mostrar(cola2);
    printf("complejidad o(n)");
  
}
