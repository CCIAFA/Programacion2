#ifndef punto6_H
#define punto6_H
#include <stdbool.h>
#include "listas.h"

typedef struct {
    int dni;
    char apellido[50];
    char nombre[50];
    char fecha[11];
} vacunado;

vacunado cargarPaciente();
void mostrarPacientesEnFecha(vacunado pacientes[], int cantidad);
int funcionHash(int fecha);
#endif 
