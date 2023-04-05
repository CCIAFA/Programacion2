#ifndef TP_Recursividad
#define TP_Recursividad

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_CARACTERES 100

// Ejercicio 1

bool palindromo(char* palabra);

bool esPalindromo(char *palabra, int inicio, int fin);

// Ejercicio 2

long producto(long a, long b);

// Ejercicio 3

long terminoSerieFibonacci (int n);

// Ejercicio 4

#define DECIMALES 4
#define INCREMENTO 1

float division2(float m, float n, int d, float r);
float division(float m, float n);

// Ejercicio 5

void agregarSeparadorMiles(char* numero, char* destino);

// Ejercicio 6

#define MAX_NIVEL_MAFIA 50

void crearVistaFrontalNivel(int n, char* cadena);

char* vistaFrontalNivel(int nivel);

// Ejercicio 7

void ondaDigitalRecursiva(char *cadena, char* resultado);

char* ondaDigital(char* cadenaOnda);

// Ejercicio 8

#define MAX_LISTA 300
/* 
   Se define un maximo de 300 caracteres para la lista de ingreso devido a que el maximo
   de un int es 32.767 (2 byte). Entonces al tener 5 caracteres por numero nos da un 
   total de 250 caracteres, mas 49 caracteres para separarlos, son 299 redondeando 300.
*/
#define MAX_LISTA_NUMEROS 50

int sumaSubconjunto(int* subconjunto, int finSubconjunto);

void subconjuntosQueSumanN(int lista[], int tamLista, int suma);

void encontrarSubconjuntosQueSumanN(int* lista, int suma, int* subconjunto, int inicio, int fin, int finSubconjunto);

// Ejercicio 9

bool divisiblePor7(long n);

// Ejercicio 10

void explotaEn(int numero, int bomba, int* resultado, int* i);

int* explosion(int numero, int bomba);

#endif //TP_Recursividad
