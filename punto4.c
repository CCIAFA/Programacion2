#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto4.h"
#include "valida.h"



void cargarLista(Lista lista){
bool continuar=true;
TipoElemento x;
int c=1;
int clave=0;
while(continuar && !(l_es_llena(lista))){
printf("\ningrese una clave:");
scanf("%i",&clave);
x=te_crear(clave);
l_agregar(lista,x);
fflush(stdin);
printf("\n ingrese 0 para salir o cualquier otro numero para seguir cargando:");
scanf("%i",&c);

if(c==0){
  continuar= false;
}
}
}
int compararListas(Lista lista1,Lista lista2){
    int resultado,i,longitudLista;
    int listaMayor1,listaMayor2,sonIguales;
    TipoElemento x1,x2;
    Iterador ite1,ite2;
    listaMayor1=0;
    listaMayor2=0;
    ite1=iterador(lista1);
    ite2=iterador(lista2);
    while(hay_siguiente(ite1)){
      x1=siguiente(ite1);
      x2=siguiente(ite2);
      if (x1->clave > x2->clave){
        listaMayor1=listaMayor1+1;
      }else if (x1->clave < x2->clave)
      {
        listaMayor2=listaMayor2+1;
      }
    }
    if(listaMayor1>listaMayor2){
      resultado=1;
    }else if (listaMayor1<listaMayor2)
    {
      resultado=2;
    }else{
      resultado=3;
    }
    return resultado;
    
}





int main() {
   Lista lista1;
   Lista lista2;
   int longitud1,longitud2,res;
   lista1=l_crear();
   lista2=l_crear();
   printf("cargue la primer lista\n");
  cargarLista(lista1);
  printf("cargue la segunda lista\n");
  cargarLista(lista2);
  longitud1=l_longitud(lista1);
  longitud2=l_longitud(lista2);
  if (longitud1==longitud2){
    res=compararListas(lista1,lista2);
    if (res==1){
      printf("la primer lista es mayor");
    }else if (res==2)
    {
      printf("la segunda lista es mayor");
    }else{
      printf("las dos listas son iguales");
    }
    
  }else{
    printf("las listas deben ser de la misma longitud para ser comparadas\n");
  }
  
}