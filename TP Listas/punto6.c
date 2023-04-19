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
    ingresarNumeroNoRep("\ningrese una clave:",&clave);
    x=te_crear(clave);
    l_agregar(lista,x);
    printf("\n ingrese 0 para salir o cualquier otro numero para seguir cargando:");
    scanf("%i",&continuar);
  }
}

int buscarLista(Lista lista, int elemento) {
    int resultado=0;
    TipoElemento x;
    Iterador ite;
    ite = iterador(lista);
    while(hay_siguiente(ite)){
        x = siguiente(ite);
        if (x->clave == elemento){
            resultado = 1;
            return resultado;
      }
    }
    return resultado;
}

int esSublista(Lista lista1,Lista lista2){
    int i=0,longitud;
    TipoElemento x1;
    Iterador ite1;
    ite1=iterador(lista1);
    longitud=l_longitud(lista2);
    while(hay_siguiente(ite1) && (i<longitud)){
      x1 = siguiente(ite1);
      if (buscarLista(lista2,x1->clave)){
          i++;
      }
    }
    if (i == longitud) {
        return 1;
    }else{
        return 0;
    }
}

int main() {
    Lista lista1;
    Lista lista2;
    int longitud1,longitud2,res;
    lista1=l_crear();
    lista2=l_crear();
    printf("cargue la primer lista\n");
    cargarLista(lista1);
    //system("cls");
    printf("cargue la segunda lista\n");
    cargarLista(lista2);
    //system("cls");
    longitud1=l_longitud(lista1);
    longitud2=l_longitud(lista2);
    l_mostrarLista(lista1);
    l_mostrarLista(lista2);
    if (longitud1>=longitud2){
        if (esSublista(lista1,lista2)){
           printf("\nLista 2 es sublista de Lista 1.\n");
        }else {
           printf("\nLista 2  NO es sublista de Lista 1.\n");
        }
    }else{
        printf("\nERROR! Lista 2 es mas grande que Lista 1.\n");
    }
    //system("pause");
    return 0;
}
