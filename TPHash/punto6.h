#ifndef PUNTO6_H
#define PUNTO6_H
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include "listas.h"

typedef struct {
    int dni;
    char apellido[50];
    char nombre[50];
} Persona;

typedef struct{
    unsigned short int dia;
    unsigned short int mes;
    unsigned short int anio;
} Fecha;

int menu();

void cargar();
void mostrar();

Persona cargarPersona();
void mostrarPersona(Persona persona);

Fecha cargarFecha();
void mostrarFecha(Fecha fecha);
#endif // PUNTO6