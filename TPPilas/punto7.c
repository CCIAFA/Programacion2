#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto7.h"
#include "utilidadesPilas.h"
#include "valida.h"
#include "pilasArreglos.c"
#include "Tipo_Elemento.c"
#include "utilidadesPilas.c"
#include "validaciones.c"

Pila elementosComun(Pila p1 ,Pila p2){
    Pila paux1,paux2,pres;
    TipoElemento x ,x2;
    bool bandera=false;
    paux1=p_crear();
    paux2=p_crear();
    pres=p_crear();
    while(!p_es_vacia(p1)){
        x=p_desapilar(p1);
        p_apilar(paux1,x);
        if(p_es_vacia(p2)){
            p_intercambiar(p2,paux2); 
        }
        while(!p_es_vacia(p2)){
            x2=p_desapilar(p2);
            p_apilar(paux2,x2);
            if(x->clave==x2->clave){
                bandera=p_buscar_clave(pres,x->clave);
                if(!bandera){
                    p_apilar(pres,x);  
                }
                
                
            }
        }
        
    }
    p_intercambiar(p1,paux1);
    p_intercambiar(p2,paux2);
    return pres;
}

int main(){
    Pila p,p2,res;
    int clave,claves;
    p=p_crear();
    p2=p_crear();
    res=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(p,clave);
    
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&claves);
    p_cargar(p2,claves);
    if(clave>claves){
        res=elementosComun(p,p2);   
    }else if (clave<claves)
    {
        res=elementosComun(p2,p);
    }else res=elementosComun(p,p2);
    
    
    printf("pila resultado\n");
    p_mostrar(res);
    printf("\npila1 original\n");
    p_mostrar(p);
    printf("\npila2 original\n");
    p_mostrar(p2);
    printf("\ncomplejidad o(n^2)\n");
}
