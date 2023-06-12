#ifndef punto4_H
#define punto4_H
#include <stdbool.h>
#include <stdint.h>
#include "listas.h"

typedef struct {
    int legajo;
    char apellido[50];
    char nombres[50];
    char domicilio[100];
    char telefono[20];
} Alumno;

Alumno cargarAlumno();
void mostrarAlumno(Alumno alumno); 
#endif 