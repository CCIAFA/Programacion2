#ifndef UTILIDADESC_H
#define UTILIDADESC_H
#include <stdbool.h>
#include "colas.h"
void p_intercambiar(Cola cola,Cola Caux);
void p_cargar(Cola cola, int cantidad);
int c_longitud(Cola cola);
bool c_buscar_clave (Cola cola, int n);
#endif 
