#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto2f.h"
#include "valida.h"


char* pasar_base(int n,int b){
    char* numero=(char*)calloc(30,1);
    Pila pila=p_crear();
    TipoElemento x;
    int resto;
    int i=0;
    while(n>0){
        resto=n % b;
        n=n/b;
        x=te_crear(resto);
        p_apilar(pila,x);
    }
    while(!p_es_vacia(pila)){
        x=p_desapilar(pila);
        if(x->clave<=9){
            *(numero+i)=48+x->clave;
        }else{
           *(numero+i)=55+x->clave; 
        }
        i++;
    }
    return numero;
}

int main() {
    int numero,base;
    char* resultado;
    ingresarNumero("\ningrese el numero: ",&numero);
    ingresarNumero("\ningrese la base: ",&base);
    resultado=pasar_base(numero,base);
    printf("numero convertido: %s",resultado);
    printf("complejidad o(log n)");
}
