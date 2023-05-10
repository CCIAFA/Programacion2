#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2f.h"
#include "valida.h"


Cola c_invertir(Cola cola){
    TipoElemento clave;
    Pila paux;
    Cola caux,caux2;
    caux=c_crear();
    caux2=c_crear();
    paux=p_crear();
    while(!c_es_vacia(cola))
    {
        clave=c_desencolar(cola);
        c_encolar(caux,clave);//guardo los elementos en una cola auxiliar para despues devolverlos a la cola original
        p_apilar(paux,clave);//guardo los valores invertidos en una pila
      
    }
    while (!p_es_vacia(paux)) {
        clave = p_desapilar(paux);
        c_encolar(caux2, clave);//cargo los valores invertidos en una segunda cola auxiliar
    }
    c_intercambiar(cola,caux);//devuelvo los elementos de la cola auxiliar a la cola original
    return caux2;//retorno la cola auxiliar con los valores invertidos
}


int main() {
    int clave,longitud1,longitud2;
    Cola cola1,cres;
    bool sonIguales;
    cola1=c_crear();
    cres=c_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);
    cres=c_invertir(cola1);
    printf("cola original:\n");
    c_mostrar(cola1);
    printf("cola invertida:\n");
    c_mostrar(cres);
  
}
