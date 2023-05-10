#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2d.h"
#include "valida.h"
#include "colas_punteros.c"
#include "utilidadesColas.c"
#include "Tipo_Elemento.c"
#include "validaciones.c"

int c_longituds(Cola cola){
int i;
Cola caux;
caux=c_crear();
i=0;
TipoElemento x;
while(!c_es_vacia(cola)){
	x=c_desencolar(cola);
	c_encolar(caux,x);
	i=i+1;
}
c_intercambiar(cola,caux);
return i;
}

int main() {
    int clave,posicion,elemento,longitud;
    Cola cola;
    cola=c_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola,clave);
    longitud=c_longituds(cola);
    printf("la cola tiene %d elementos",longitud);
    
}