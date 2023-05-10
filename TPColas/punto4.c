#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto4.h"
#include "valida.h"
#include "colas_punteros.c"
#include "utilidadesColas.c"
#include "Tipo_Elemento.c"
#include "validaciones.c"

Cola c_no_repetidos(Cola cola){
    Cola caux;
    TipoElemento clave;
    caux=c_crear();
    bool bandera=false;
    int i=0;
    int longitud;
    longitud=c_longitud(cola);
    while(i<longitud){
        clave=c_desencolar(cola);
        bandera=c_buscar_clave(cola,clave->clave);
        if(!bandera){
            c_encolar(caux,clave);
            c_encolar(cola,clave);
        }else{
            c_encolar(cola,clave);
        }
        i++; 
    }
    return caux;
}


int main() {
    int clave;
    Cola cola1,cres;
    cola1=c_crear();
    cres=c_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);
    cres=c_no_repetidos(cola1);
    printf("cola original:\n");
    c_mostrar(cola1);
    printf("cola sin repetidos:\n");
    c_mostrar(cres);
}