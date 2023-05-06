#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2f.h"
#include "valida.h"
#include "utilidadesPilas.h"
#include "pilasArreglos.c"
#include "Tipo_Elemento.c"
#include "utilidadesPilas.c"
#include "validaciones.c"

bool p_son_iguales(Pila pila1,Pila pila2){
    TipoElemento clave,clave2;
    bool iguales=true;
    Pila paux ,paux2;
    paux=p_crear();
    paux2=p_crear();
    while(!p_es_vacia(pila1))
    {
        clave=p_desapilar(pila1);
        clave2=p_desapilar(pila2);
        p_apilar(paux,clave);
        p_apilar(paux2,clave2);
        if(clave->clave!=clave2->clave){
            iguales=false;
        }
    }
    
    return iguales;
}


int main() {
    int clave,longitud1,longitud2;
    Pila pila1,pila2;
    bool sonIguales;
    pila1=p_crear();
    pila2=p_crear();
    printf("pila1:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila1,clave);
    printf("pila2:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila2,clave);
    longitud1=p_longitud(pila1);
    longitud2=p_longitud(pila2);
    if(longitud1==longitud2){
        sonIguales=p_son_iguales(pila1,pila2);
        if(sonIguales){
            printf("las pilas son iguales");
        }else{
            printf("las pilas no son iguales");
        }  
    }else{
        printf("las pilas no son iguales");
    }
    
  
}