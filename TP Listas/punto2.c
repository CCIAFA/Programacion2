#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "punto2.h"

int generarNumeroAleatorio(int min, int max) {
    static int iniciarSemilla = 1;
    //Esto es para que solo se inicie una vez la semilla
    if (iniciarSemilla) {
        srand(time(NULL));
        iniciarSemilla = 0;
    } 
    return min + (rand() % (max - min + 1));
}

void cargarListaAleatoria(Lista lista, int cantidad){
  TipoElemento x;
  int i = 0;
  int clave = 0;
  while(i<cantidad && !(l_es_llena(lista))){
    clave = generarNumeroAleatorio(RANGO_MINIMO,RANGO_MAXIMO);
    x=te_crear(clave);
    l_agregar(lista,x);
    i++;
  }
}

void menorLista(Lista lista, int *menor, int *pos){
    int resultado,i = 0;
    TipoElemento te1;
    Iterador ite;
    ite=iterador(lista);
    if (hay_siguiente(ite)){
    te1=siguiente(ite);
    // Toma el primer elemento como menor para luego hacer las comparaciones
        (*pos) = i;
        (*menor) = te1->clave;
    }
    while(hay_siguiente(ite)){
      te1=siguiente(ite);
      i++;
      if (te1->clave < *menor){
        (*menor) = te1->clave;
        (*pos) = i;
      } 
    }
}

void mayorLista(Lista lista, int *mayor, int *cantidad){
    int i;
    TipoElemento te1;
    Iterador ite;
    ite=iterador(lista);
    if (hay_siguiente(ite)){
    te1=siguiente(ite);
    // Toma el primer elemento como mayor para luego hacer las comparaciones
        (*cantidad) = 1;
        (*mayor) = te1->clave;
    }
    while(hay_siguiente(ite)){
      te1=siguiente(ite);
      i++;
      if (te1->clave == *mayor){
          (*cantidad)++;
      }else if (te1->clave > *mayor){
          (*cantidad) = 1;
          (*mayor) = te1->clave;
      }
    } 
}

float promedioRecursivo(Lista lista, Iterador ite, float* suma, int longitud){
    TipoElemento x;
    if(hay_siguiente(ite)) {
        x=siguiente(ite);    
        (*suma) += x->clave;
        return promedioRecursivo(lista,ite,suma,longitud);
    }
    return (*suma)/(float)longitud;
}

float promedio(Lista lista){
    TipoElemento x1;
    Iterador ite;
    ite=iterador(lista);
    float suma = 0;
    int longitud;
    longitud=l_longitud(lista);
    return promedioRecursivo(lista, ite, &suma, longitud);
}

Lista listaMultiplo(Lista lista, int numero){
    Lista listaResultado;
    listaResultado = l_crear();
    TipoElemento x1,x;
    Iterador ite1;
    int clave;
    ite1=iterador(lista);
    while(hay_siguiente(ite1)){
      x1=siguiente(ite1);
      clave = numero*x1->clave;
      x=te_crear(clave);
      l_agregar(listaResultado,x);
    }
    return listaResultado;
}

int main() {
    Lista lista1;
    Lista lista2;
    int longitud1,longitud2;
    int menor, pos, mayor, cantidad,multiplo;
    lista1=l_crear();
    lista2=l_crear();
    printf("Se carga la lista con numeros aleatorios\n");
    printf("Ingrese la cantidad de numeros que contendra la lista: ");
    scanf("%i",&cantidad);
    printf("Ingrese el numero por el que se va a multiplicar la lista: ");
    scanf("%i",&multiplo);
    
    cargarListaAleatoria(lista1, cantidad);
    printf("-----------------------------------------------------------\n");
    printf("Lista generada:\n");
    l_mostrarLista(lista1);
    printf("-----------------------------------------------------------\n");
    menorLista(lista1, &menor, &pos);
    printf("a - El numero menor es %d en la posicion %d\n",menor, pos);
    mayorLista(lista1, &mayor, &cantidad);
    printf("b - El numero mayor es %d y se repite %d veces\n",mayor, cantidad);
    printf("c - El promedio de la lista es: %f\n",promedio(lista1));
    printf("d - Lista multiplo de %d: \n",multiplo);
    lista2 = listaMultiplo(lista1,multiplo);
    l_mostrarLista(lista2);
    
    system("pause");
    return 0;
}
