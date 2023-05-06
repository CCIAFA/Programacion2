#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto6.h"
#include "utilidadesPilas.h"
#include "valida.h"
#include "pilasArreglos.c"
#include "Tipo_Elemento.c"
#include "utilidadesPilas.c"
#include "validaciones.c"




Pila eliminarOcurrenciasRec(Pila pila, int elemento) {
    if (p_es_vacia(pila)) {
        return p_crear();
    } else {
        TipoElemento x = p_desapilar(pila);
        Pila paux = eliminarOcurrenciasRec(pila, elemento);
        if (x->clave != elemento) {
            p_apilar(paux, x);
        }
        p_apilar(pila, x);
        return paux;
    }
}


int main(){
    Pila p,res;
    int clave;
    p=p_crear();
    res=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(p,clave);
    ingresarNumero("\ningrese el numero a eliminar: ",&clave);
    res=eliminarOcurrenciasRec(p,clave);
    printf("pila resultado\n");
    p_mostrar(res);
    printf("\npila original\n");
    p_mostrar(p);
    printf("complejidad o(n)");
}