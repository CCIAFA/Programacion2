#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "punto5.h"

void cargarPolinomio(Lista lista){
  int continuar = 1;
  TipoElemento x;
  int clave = 0;
  printf("\nIngrese los coeficientes comenzando por el termino independiente.\n");
  while(continuar && !(l_es_llena(lista))){
    printf("\ningrese una clave:");
    scanf("%i",&clave);
    x=te_crear(clave);
    l_agregar(lista,x);
    fflush(stdin);
    printf("\n ingrese 0 para salir o cualquier otro numero para seguir cargando:");
    scanf("%i",&continuar);

  }
}

float valorEnX(Lista funcion, float x){
    int resultado,i = 0;
    float acum = 0;
    TipoElemento te1;
    Iterador ite;
    ite=iterador(funcion);
    if (hay_siguiente(ite)){
    // Suma el termino independiente al acumulador
        te1=siguiente(ite);
        acum += te1->clave;
    }
    while(hay_siguiente(ite)){
    // Va sumando los coeficientes multiplicados por las potencias de 10
      te1=siguiente(ite);
      acum += te1->clave * x * pow(10,i);
      i++;
    } 
    return acum;
}

Lista calculoDeFuncionEnRango(Lista polinomio, Lista listaResultado, float inicio, float fin, float paso){
    float i = inicio;
    TipoElemento x;
    float clave = 0;
    while((i<=fin) && !(l_es_llena(polinomio))){
        clave = valorEnX(polinomio,i);
        i+= paso;
        x=te_crear(clave);
        l_agregar(listaResultado,x);
    }
    return listaResultado;
} 


int main() {
    Lista polinomio;
    polinomio=l_crear();
    Lista resultados;
    resultados=l_crear();
    printf("Cargue el polinomio:\n");
    cargarPolinomio(polinomio);
    printf("\nCoeficientes: \n");
    l_mostrarLista(polinomio);
    resultados = calculoDeFuncionEnRango(polinomio,resultados,-1,1,0.5);
    printf("\nResultados: \n");
    l_mostrarLista(resultados);


    //system("pause");
    return 0;
}
