#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto7.h"
#include "valida.h"
#include "colas_arreglo_circular.c"
#include "utilidadesColas.c"
#include "Tipo_Elemento.c"
#include "validaciones.c"




void atender_clientes(Cola cola1,Cola cola2, Cola cola3,int tiempo){
    Cola Caux1,Caux2,Caux3;
    int c1,c2,c3,i1,i2,i3;
    int longitud1,longitud2,longitud3;
    TipoElemento clave1,clave2,clave3;
    bool primero=true;
    bool primero2=true;
    bool primero3=true;
    Caux1=c_crear();
    Caux2=c_crear();
    Caux3=c_crear();
    i1=1;
    i2=1;
    i3=1;
    longitud1=c_longitud(cola1);
    longitud2=c_longitud(cola2);
    longitud3=c_longitud(cola3);
    while(!c_es_vacia(cola1)||!c_es_vacia(cola2)||!c_es_vacia(cola3)){
        if (!c_es_vacia(cola1)) {//mientras la cola no este vacia ejecuta el codigo
            if(primero){
              //no se desencola porque si el elemento es mas grande que tiempo solo pasa por un cilco
              clave1=c_recuperar(cola1);//tomo el primer elemento
              //c_encolar(Caux1,clave1);
              primero=false;
              c1=clave1->clave;//asigno el valor del primer elemento a c1
            }
            
            c1=c1-tiempo;//resto c1 por tiempo
            if(c1<=0){//si la resta da 0 o negativo
                c_encolar(Caux1,clave1);//guardo el elemento en caux
                c_desencolar(cola1);//quito el elemento anterior
                clave1=c_recuperar(cola1);//recupero el siguiente elemento
                if(clave1!=NULL){
                  c1=clave1->clave;
                }
                
                printf("cliente %d cola1\n",i1);//imprimo el cliente
                 i1++;  
            }
            
        }
        if (!c_es_vacia(cola2)) {//mientras la cola no este vacia ejecuta el codigo
            if(primero2){
              //no se desencola porque si el elemento es mas grande que tiempo solo pasa por un cilco
              clave2=c_recuperar(cola2);//tomo el primer elemento
              //c_encolar(Caux1,clave1);
              primero2=false;
              c2=clave2->clave;//asigno el valor del primer elemento a c2
            }
            
            c2=c2-tiempo;//resto c2 por tiempo
            if(c2<=0){//si la resta da 0 o negativo
                c_encolar(Caux2,clave2);//guardo el elemento en caux
                c_desencolar(cola2);//quito el elemento anterior
                clave2=c_recuperar(cola2);//recupero el siguiente elemento
                if(clave2!=NULL){
                  c2=clave2->clave;
                }
                
                printf("cliente %d cola2\n",i2);//imprimo el cliente
                 i2++;  
            }
            
        }
      if (!c_es_vacia(cola3)) {//mientras la cola no este vacia ejecuta el codigo
            if(primero3){
              //no se desencola porque si el elemento es mas grande que tiempo solo pasa por un cilco
              clave3=c_recuperar(cola3);//tomo el primer elemento
              //c_encolar(Caux1,clave1);
              primero3=false;
              c3=clave3->clave;//asigno el valor del primer elemento a c3
            }
            
            c3=c3-tiempo;//resto c3 por tiempo
            if(c3<=0){//si la resta da 0 o negativo
                c_encolar(Caux3,clave3);//guardo el elemento en caux
                c_desencolar(cola3);//quito el elemento anterior
                clave3=c_recuperar(cola3);//recupero el siguiente elemento
                if(clave3!=NULL){
                  c3=clave3->clave;
                }
                
                printf("cliente %d cola3\n",i3);//imprimo el cliente
                 i3++;  
            }
            
        }

        
    }
    c_intercambiar(cola1,Caux1);
    c_intercambiar(cola2,Caux2);
    c_intercambiar(cola3,Caux3);
}





int main() {
    int tiempo,clave;
    Cola cola1,cola2,cola3;
    cola1=c_crear();
    cola2=c_crear();
    cola3=c_crear();
    printf("cola1");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);
    printf("cola2");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola2,clave);
    printf("cola3");
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola3,clave);
    ingresarNumeroMayor("\ningrese el tiempo: ",&clave,0);
    tiempo=clave;
    atender_clientes(cola1,cola2,cola3,tiempo);
    printf("cola1\n");
    c_mostrar(cola1);
    printf("cola2\n");
    c_mostrar(cola2);
    printf("cola3\n");
    c_mostrar(cola3);
}
