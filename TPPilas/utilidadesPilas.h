#ifndef UTILIDADESP_H
#define UTILIDADESP_H
#include <stdbool.h>
#include "pilas.h"
void p_intercambiar(Pila pila,Pila Paux);
void p_cargar(Pila pila, int cantidad);
bool p_buscar_clave(Pila pila, int n);
TipoElemento p_traer_clave (Pila pila, int n);
void p_mostrar_todo(Pila pila);
int p_longitud(Pila pila);
#endif 
