#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2b.h"
#include "utilidadesPilas.h"
#include "pilasArreglos.c"
#include "Tipo_Elemento.c"
#include "utilidadesPilas.c"
#include "validaciones.c"

Pila p_insertar(Pila pila,int pos,int x){
    TipoElemento clave;
    int i=1;
    int longitud;
    longitud=p_longitud(pila);
    Pila paux,pres;
    paux=p_crear();
    while(!p_es_vacia(pila) && i <= pos){
        if(pos==1){//si se quiere insertar en la primera posicion se apila directamente y termina el programa
            clave=te_crear(x);
            p_apilar(pila,clave);
            break;
           
        }else if (i==pos){//si i es igual a la posicion se inserta el elemento en la pila y luego se intercambia con paux
           clave = te_crear(x);
            p_apilar(pila, clave);
            break;
        }else{//si i no es igual a la posicion se sigue desapilando y se suma i
           clave = p_desapilar(pila);
            p_apilar(paux, clave);
            
        }
        i=i+1;
        
    }
    if(p_es_vacia(pila)){
        clave=te_crear(x);
        p_apilar(pila,clave); 
    }
    p_intercambiar(pila,paux);
    return pila;
}


int main() {
    bool res;
    int clave,posicion,elemento,longitud;
    Pila pila1,pres;
    pila1=p_crear();
    pres=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila1,clave);
    longitud=p_longitud(pila1);
    ingresarNumero("\ningrese la posicion a insertar : ",&posicion);
    ingresarNumero("\ningrese el elemento a insertar : ",&elemento);
    if(posicion >longitud+1){
        printf("no se puede insertar en la posicion dada");
    }else{
        pres=p_insertar(pila1,posicion,elemento);
        p_mostrar(pres);  
    }
    
}