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

Pila p_invertir(Pila pila){
    TipoElemento clave,clave2;
    Pila paux ,paux2;
    paux=p_crear();
    paux2=p_crear();
    while(!p_es_vacia(pila))
    {
        clave=p_desapilar(pila);
        p_apilar(paux,clave);
        p_apilar(paux2,clave);
      
    }
    p_intercambiar(pila,paux);
    return paux2;
}


int main() {
    int clave,longitud1,longitud2;
    Pila pila1,pres;
    bool sonIguales;
    pila1=p_crear();
    pres=p_crear();
    printf("pila1:\n");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila1,clave);
    pres=p_invertir(pila1);
    printf("pila original:\n");
    p_mostrar(pila1);
    printf("pila invertida:\n");
    p_mostrar(pres);
    printf("complejidad o(n)");
}