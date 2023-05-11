#include "utilidadesColas.h"
#include "utilidadesPilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto6.h"
#include "valida.h"

void l_mostrarTodo(Lista lista){
 printf("Contenido de la lista: ");
    for (int i = 0; i < lista->cantidad; i++) {
        printf("{%d:%s}-", lista->valores[i]->clave,(char*)lista->valores[i]->valor);
    }
    printf("\n");
 
}

Lista valores_comunes(Cola cola,Pila pila){
    Cola caux;
    Pila paux;
    Lista Lres;
    TipoElemento clave;
    int posP,posC,longitudP,longitudC,longitud,i;
    char valor[100];
    longitudP=p_longitud(pila);
    longitudC=c_longitud(cola);
   
    caux=c_crear();
    paux=p_crear();
    Lres=l_crear();
    
    i=0;
    if(longitudP>longitudC){//si la pila es mas grande que la cola ejecuto este codigo
        posP=1;
        while(!p_es_vacia(pila)){
        clave=p_desapilar(pila);//traigo la primer clave de la pila
        p_apilar(paux,clave);
        posC=c_buscar_posicion(cola,clave->clave);//busco si la clave esta en la cola y si esta me trae la posicion
        if(posC!=-1){//si esta en la cola pongo las posiciones en la parte valor y despues lo agrego a la lista
            sprintf(valor, "%d,%d", posP, posC);
            clave->valor = strdup(valor);
            l_agregar(Lres,clave);

        }
       posP++;
       i++;
       
    }
    p_intercambiar(pila,paux);
    }else{//si la cola es mas grande que la pila ejecuto este codigo
       posC=1; 
       while(!c_es_vacia(cola)){
        clave=c_desencolar(cola);//traigo la primer clave de la cola
        c_encolar(caux,clave);
        posP=p_buscar_posicion(pila,clave->clave);//busco si la clave esta en la pila y si esta me trae la posicion
        if(posP!=-1){//si esta en la pila pongo las posiciones en la parte valor y despues lo agrego a la lista
            sprintf(valor, "%d,%d", posP, posC);
            clave->valor = strdup(valor);
            l_agregar(Lres,clave);
        }
       posC++;
       i++;  
    }
     c_intercambiar(cola,caux);
    }
    return Lres;
}


int main() {
    int clave,pos;
    Cola cola1;
    Pila pila;
    Lista lista;
    bool col,pil;
    cola1=c_crear();
    pila=p_crear();
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    c_cargar(cola1,clave);
    ingresarNumero("\ningrese la cantidad de elementos que quiera cargar: ",&clave);
    p_cargar(pila,clave);
    col=c_tiene_repetidos(cola1);
    pil=p_tiene_repetidos(pila);
    if(!col && !pil){
        lista=valores_comunes(cola1,pila);
        printf("cola original:\n");
        c_mostrar(cola1);
        printf("pila original:\n");
        p_mostrar(pila);
        printf("---numero:posicion pila,posicion cola-\n");
        l_mostrarTodo(lista);
        printf("complejidad o(n^2)");   
    }else{
        printf("la cola o la pila tienen elementos repetidos");
    }
    
}

