#ifndef Punto5
#define Punto5
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "listas.h"

void cargarPolinomio(Lista lista);
float valorEnX(Lista funcion, float x);
Lista calculoDeFuncionEnRango(Lista polinomio,Lista listaResultado, float inicio, float fin, float paso);

#endif //Punto5

