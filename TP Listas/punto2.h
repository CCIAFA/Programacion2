#ifndef Punto2
#define Punto2

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "listas.h"

#define RANGO_MINIMO -32000
#define RANGO_MAXIMO 32000

int generarNumeroAleatorio(int min, int max);
void cargarListaAleatoria(Lista lista, int cantidad);
void menorLista(Lista lista, int *menor, int *pos);
void mayorLista(Lista lista, int *mayor, int *cantidad);
float promedioRecursivo(Lista lista, Iterador ite, float* suma, int longitud);
float promedio(Lista lista);
Lista listaMultiplo(Lista lista, int numero);

#endif //Punto2
