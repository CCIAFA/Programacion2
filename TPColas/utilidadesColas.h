#ifndef UTILIDADESC_H
#define UTILIDADESC_H
#include <stdbool.h>
#include "colas.h"
void c_intercambiar(Cola cola,Cola Caux);
void c_cargar(Cola cola, int cantidad);
int c_longitud(Cola cola);
bool c_buscar_clave (Cola cola, int n);
int c_buscar_posicion (Cola cola, int n);
Cola c_duplicar(Cola cola);
bool c_tiene_repetidos(Cola cola);
void c_cargar_no_repetidos(Cola cola, int cantidad);
#endif 
