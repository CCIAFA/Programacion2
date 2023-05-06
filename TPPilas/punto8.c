#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto8.h"
#include "utilidadesPilas.h"
#include "valida.h"
#include "pilasArreglos.c"
#include "Tipo_Elemento.c"
#include "utilidadesPilas.c"
#include "validaciones.c"

Pila cantidadApariciones(Pila pila){
    Pila paux1,pres;
    TipoElemento x,clave;
    int temp;
    paux1=p_crear();
    pres=p_crear();
    while (!p_es_vacia(pila))//recorro toda la pila
    {
        x=p_desapilar(pila);
        p_apilar(paux1,x);//guardo los elementos de la pila en una auxiliar
        if(p_es_vacia(pres)){//si es el primer elemento le pongo la repeticion en uno y lo apilo en la pila resultado
            int* repeticiones = malloc(sizeof(int));
            *repeticiones = 1;
            x->valor = repeticiones;
            p_apilar(pres,x); 
        }else{
            clave=p_traer_clave(pres,x->clave);//busco si el elemento esta en la pila resultado y lo traigo
            if(clave!=NULL){//si existe se le suma las repeticiones y se lo vuelve a apilar en la pila resultado
            int* repeticiones = malloc(sizeof(int));
            *repeticiones = *(int*)clave->valor + 1;
            clave->valor = repeticiones;
            p_apilar(pres,clave);
            }else {
                int* repeticiones = malloc(sizeof(int));
                *repeticiones = 1;
                x->valor = repeticiones;
                p_apilar(pres,x);    
            }       
       
        }
       
    }
    p_intercambiar(pila,paux1);//devuelvo todos los elementos a la pila original
    return pres;
}
int main(){
    Pila p,res;
    int clave,claves;
    p=p_crear();
    res=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(p,clave);
    res=cantidadApariciones(p);
    printf("pila original:\n");
    p_mostrar(p);
    printf("pila resultado:\n");
    p_mostrar_todo(res);
    printf("complejidad o(n^2)");
}