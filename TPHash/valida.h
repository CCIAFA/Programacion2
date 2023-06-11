#ifndef Valida
#define Valida

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


bool validaRango(int numero, int nInf, int nSup);

int esNumero(char* cadena);

void ingresarNumero(char* texto, int* numero);

void ingresarNumeroSin0(char* texto, int* numero);   
//void ingresarNumero(char* texto, float* numero);

void ingresarNumeroMayor(char* texto, int* numero,int limite);

void ingresarNumeroMenor(char* texto, int* numero,int limite);

int ingresarNumeroEntre(char* texto, int nInf, int nSup);

bool cadenaVacia( char* cadena);
	
void ingresarCadena(char* cadena);

bool contieneEspacios(char* cadena);

void ingresarCadenaSinEspacios(char* cadena);

void eliminaEspacios(char* cadena, char* cadenaSinEspacios);

bool cadenaDeEspacios(char* cadena);

void noIngresarCadenaDeEspacios(char* cadena);

void pasarMinusculas(char* cadena);

bool soloNumeros(char* cadena);

void cadenaDeNumeros(char* cadena);

void ingresarOndaDigital(char* cadena);

//void mostrarResultadoEnLista(int *lista);
void mostrarResultadoEnLista(int *lista, int inicio);

void mostrarSubconjuntoEnPantalla(int* subconjunto, int finSubconjunto);

int divisionEntera(int n1, int n2);

int separarEnteros(char* lista, int* resultado);
#endif // Valida
