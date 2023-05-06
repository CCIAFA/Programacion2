#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2c.h"
#include "valida.h"
#include "utilidadesPilas.h"
#include "pilasArreglos.c"
#include "Tipo_Elemento.c"
#include "utilidadesPilas.c"
#include "validaciones.c"



void p_eliminar(Pila pila,int elemento){
    TipoElemento clave;
    Pila paux;
    bool bandera=false;
    paux=p_crear();
    while(!p_es_vacia(pila)){
        clave=p_desapilar(pila);
        if(clave->clave==elemento&&!bandera){
            bandera=true;
        }else{
            p_apilar(paux,clave);
        }
    }
    p_intercambiar(pila,paux);
}

int main() {
    int clave,posicion,elemento,longitud;
    Pila pila1,pres;
    pila1=p_crear();
    
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila1,clave);
    longitud=p_longitud(pila1);
    ingresarNumero("\ningrese el elemento a eliminar : ",&elemento);
    if(longitud==0){
        printf("la pila esta vacia");
    }else{
        p_eliminar(pila1,elemento);
        p_mostrar(pila1);  
    }
    
}