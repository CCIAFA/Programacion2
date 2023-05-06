#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2f.h"
#include "valida.h"
#include "utilidadesPilas.h"

int p_longituds(Pila pila){
int i;
Pila paux;
paux=p_crear();
i=0;
TipoElemento x;
while(!p_es_vacia(pila)){
	x=p_desapilar(pila);
	p_apilar(paux,x);
	i=i+1;
}
p_intercambiar(pila,paux);
return i;
}

int main() {
    int clave,posicion,elemento,longitud;
    Pila pila1;
    pila1=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila1,clave);
    longitud=p_longituds(pila1);
    printf("la pila tiene %d elementos",longitud);
    
}
