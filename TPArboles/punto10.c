#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto10.h"
#include "valida.h"


NodoArbol crearNodo(int dato) {
    NodoArbol nodo;
    nodo->datos = dato;
    nodo->hi = NULL;
    nodo->hd = NULL;
    return nodo;
}

// Función para insertar un nodo en un árbol binario de búsqueda
NodoArbol insertarEnABB(NodoArbol raiz, int dato) {
    if (raiz == NULL) {
        return crearNodo(dato);
    }
    
    if (dato < raiz->datos) {
        raiz->hi = insertarEnABB(raiz->hi, dato);
    } else if (dato > raiz->datos) {
        raiz->hd = insertarEnABB(raiz->hd, dato);
    }
    
    return raiz;
}

// Función para calcular la altura de un árbol binario
int calcularAltura(NodoArbol raiz) {
    if (raiz == NULL) {
        return 0;
    }
    
    int alturaIzquierdo = calcularAltura(raiz->hd);
    int alturaDerecho = calcularAltura(raiz->hd);
    
    return (alturaIzquierdo > alturaDerecho ? alturaIzquierdo : alturaDerecho) + 1;
}


void cargarSeriesEnArboles(int n) {
   
    NodoArbol abb = NULL;
    NodoArbol avl = NULL;
    
    int i;
    for (i = 0; i < n; i++) {
        int numero = rand() % 100; // Genera números aleatorios entre 0 y 99
        
        // Cargar en árbol binario de búsqueda
        abb = insertarEnABB(abb, numero);
        
        // Cargar en árbol AVL
        avl = insertarEnAVL(avl, numero);
    }
    
    int alturaABB = calcularAltura(abb);
    int alturaAVL = calcularAltura(avl);
    
    printf("Altura del árbol binario de búsqueda: %d\n", alturaABB);
    printf("Altura del árbol AVL: %d\n", alturaAVL);
    
  
}

// Función principal
int main() {
    int n;
    printf("Ingrese el número de repeticiones: ");
    scanf("%d", &n);
    
    cargarSeriesEnArboles(n);
    
    return 0;
}


/*
Se puede ver que al aumentar n veces progresivamente la insercion de nodos, 
el Arbol de busqueda Binario puede degenerarse y terminar con complejidad lineal dado que no se va equilibrando, 
a diferencia del AVL.
De esta forma el AVL tendra por lo general una menor altura que el binario de busqueda sin factor de equilibrio implementado.
*/

