#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto5.h"
#include "valida.h"
#include "colas_punteros.c"
#include "utilidadesColas.c"
#include "Tipo_Elemento.c"
#include "validaciones.c"

//el programa solo funciona con el primer elemento y este se pierde en la cola original
//ahora tener en cuenta que se pueden dividir por si mismos
void c_buscar_divisores2(Cola cola){
    Cola caux,copia;
    TipoElemento clave,divisor;
    int longitud,i,acumulador;
    bool primero =true;
    longitud=c_longitud(cola);
    caux=c_crear();
    i=0;
    
    while(i<longitud){
        if(primero){
        divisor=c_desencolar(cola);//tomo el primer elemento y lo llamo divisor
        c_encolar(caux,divisor);//revisar esto//encolo el primer elemento
        
        primero=false;  
        }else{
            if (acumulador==longitud-1){//si se dividio todos los elementos es divisor total
                
                printf("%d es divisor total\n",divisor->clave);
                divisor=c_recuperar(cola);
            }else if (acumulador>=longitud/2){//si se dividio mas de la mitad es divisor parcial
                divisor=c_recuperar(cola);
                printf("%d es divisor parcial\n",divisor->clave);
            }    
        }
        
        acumulador=0;
        while(!c_es_vacia(cola)){
            clave=c_desencolar(cola);//tomo el siguiente elemento de la cola
            c_encolar(caux,clave);
            
            if(clave!=NULL){
              if(clave->clave %  divisor->clave == 0){//hago la division si es entero lo acumulo
                acumulador=1+acumulador;
              }  
            }
           
        }
        i++;
        c_intercambiar(cola,caux);
    }
    c_intercambiar(cola,caux);
    //clave=c_desencolar(cola);
    //c_encolar(cola,clave);
}

void c_buscar_divisores(Cola cola) {
    Cola copia = c_crear();
    int longitud = c_longitud(cola);
    int divisor_total = -1; //asumimos que no hay divisor total
    int contador_parcial = 0;
    //Hacemos una copia de la cola para no modificar la original
    copia=c_duplicar(cola);
    
    //Comprobamos si cada elemento es divisor total o parcial
    while(!c_es_vacia(copia)) {
        TipoElemento divisor = c_desencolar(copia);
        int contador = 0;
        for(int i = 0; i < longitud; i++) {
            TipoElemento elemento = c_desencolar(cola);
            if(elemento->clave % divisor->clave == 0) {
                contador++;
            }
            c_encolar(cola, elemento);
        }
        if(contador == longitud) {
            divisor_total = divisor->clave;
        } else if(contador >= longitud/2) {
            printf("%d es divisor parcial\n", divisor->clave);
        }
    }
    if(divisor_total != -1) {
        printf("%d es divisor total\n", divisor_total);
    } else {
        printf("No hay divisor total\n");
    }
}

int main() {
    int clave,pos;
    Cola cola1;
    bool col,pil;
    cola1=c_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar_mayores_no_rep(cola1,clave,1);
    c_buscar_divisores(cola1);
    printf("cola original:\n");
    c_mostrar(cola1);
    printf("complejidad o(n^2)");   
       
}


