#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto6.h"
#include "valida.h"


void cargarLista(Lista lista){
  int continuar = 1;
  TipoElemento x;
  int clave = 0;
  while(continuar && !(l_es_llena(lista))){
    ingresarNumero("\ningrese una clave:",&clave);
    x=te_crear(clave);
    l_agregar(lista,x);
    printf("\n ingrese 0 para salir o cualquier otro numero para seguir cargando:");
    scanf("%i",&continuar);
  }
}

int esMultiplo(Lista lista1,Lista lista2){
    TipoElemento x1,x2;
    Iterador ite1,ite2;
    ite1=iterador(lista1);
    ite2=iterador(lista2);
    while(hay_siguiente(ite1)){
      x1=siguiente(ite1);
      x2=siguiente(ite2);
      if (x2->clave % x1->clave == 0){
        if (!(abs(x2->clave)==1) && (abs(x1->clave) == 1)){
           return 0;
        }
      } else {
          return 0;
      }
    }
   
    return 1;
    
}

int main() {
    Lista lista1;
    Lista lista2;
    int longitud1,longitud2,res;
    lista1=l_crear();
    lista2=l_crear();
    printf("cargue la primer lista\n");
    cargarLista(lista1);
    system("cls");
    printf("cargue la segunda lista\n");
    cargarLista(lista2);
    system("cls");
    longitud1=l_longitud(lista1);
    longitud2=l_longitud(lista2);
    l_mostrarLista(lista1);
    l_mostrarLista(lista2);
    if (longitud1==longitud2){
        if (esMultiplo(lista1,lista2)){
           printf("\nLista 2 es multiplo de Lista 1.\n");
        }else {
           printf("\nLista 2  NO es multiplo de Lista 1.\n");
        }
    }else{
        printf("\nERROR! El tamaño de la lista deben ser iguales\n");
    }
    system("pause");
    return 0;
}
