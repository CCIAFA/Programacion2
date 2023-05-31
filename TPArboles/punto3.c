#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto3.h"
#include "valida.h"

void buscar_padreint(NodoArbol nodo, int clave) {
    if (nodo == NULL) {
        return;
    }

    if((n_hijoderecho(nodo)!=NULL&&n_hijoderecho(nodo)->datos->clave==clave)||(n_hijoizquierdo(nodo)!=NULL&&n_hijoizquierdo(nodo)->datos->clave==clave)){
        printf("el padre del nodo es: %d\n",nodo->datos->clave);
        return;
    }

    buscar_padreint(n_hijoizquierdo(nodo), clave);
    buscar_padreint(n_hijoderecho(nodo), clave);
}

void a_buscar_padre(ArbolBinario a, int clave) {
    buscar_padreint(a_raiz(a), clave);
    
}

void buscar_hijosint(NodoArbol nodo, int clave) {
    NodoArbol hd,hi;
    if (nodo == NULL) {
        return;
    }

    if(nodo->datos->clave==clave){
        hd=n_hijoderecho(nodo);
        hi=n_hijoizquierdo(nodo);
        if(hi!=NULL){
            printf("el hijo izquierdo del nodo es: %d\n",hi->datos->clave);
        }
        if(hd!=NULL){
            printf("el hijo derecho del nodo es: %d\n",hd->datos->clave);
        }
        return;
    }

    buscar_hijosint(n_hijoizquierdo(nodo), clave);
    buscar_hijosint(n_hijoderecho(nodo), clave);
}

void a_buscar_hijos(ArbolBinario a, int clave) {
    buscar_hijosint(a_raiz(a), clave);
    
}

void buscar_hermanoint(NodoArbol nodo, int clave) {
     if (nodo == NULL) {
        return;
    }

    if (n_hijoizquierdo(nodo) != NULL && n_hijoizquierdo(nodo)->datos->clave == clave) {
        if (n_hijoderecho(nodo) != NULL) {
            printf("El hermano del nodo es: %d\n", n_hijoderecho(nodo)->datos->clave);
            return;
        }
    }

    if (n_hijoderecho(nodo) != NULL && n_hijoderecho(nodo)->datos->clave == clave) {
        if (n_hijoizquierdo(nodo) != NULL) {
            printf("El hermano del nodo es: %d\n", n_hijoizquierdo(nodo)->datos->clave);
            return;
        }
    }

    buscar_hermanoint(n_hijoizquierdo(nodo), clave);
    buscar_hermanoint(n_hijoderecho(nodo), clave);
}

void a_buscar_hermano(ArbolBinario a, int clave) {
    buscar_hermanoint(a_raiz(a), clave);
    
}

int buscar_nivelint(NodoArbol nodo, int clave,int nivel_actual) {
   if (nodo == NULL) {
        return -1; // Nodo no encontrado
    }
    
    if (nodo->datos->clave == clave) {
        return nivel_actual; // Se encontró el nodo, se retorna el nivel actual
    }
    
    // Buscar en el subárbol izquierdo
    int nivel_izquierdo = buscar_nivelint(nodo->hi, clave, nivel_actual + 1);
    if (nivel_izquierdo != -1) {
        return nivel_izquierdo; // Se encontró el nodo en el subárbol izquierdo
    }
    
    // Buscar en el subárbol derecho
    int nivel_derecho = buscar_nivelint(nodo->hd, clave, nivel_actual + 1);
    return nivel_derecho; // Puede ser -1 si no se encontró el nodo en el subárbol derecho
}

int a_nivel(NodoArbol nodo, int clave) {
    int i;
    i=buscar_nivelint(nodo, clave,0);
    if(i!=-1){
        
        return i; 
    }else return -1;
}

int calcular_altura(NodoArbol nodo) {
    if (nodo == NULL) {
        return 0; // Altura de un nodo nulo es 0
    }
    
    // Calcular la altura de los subárboles izquierdo y derecho
    int altura_izquierdo = calcular_altura(nodo->hi);
    int altura_derecho = calcular_altura(nodo->hd);
    
    // La altura del subárbol es la máxima altura entre los subárboles izquierdo y derecho, más 1 por el nodo actual
    return (altura_izquierdo > altura_derecho) ? altura_izquierdo + 1 : altura_derecho + 1;
}

void obtener_altura_rama(ArbolBinario a, int clave) {
    int alt;
    NodoArbol nodo = buscar_nodo(a_raiz(a), clave);
    if (nodo != NULL) {
        alt=calcular_altura(nodo);
        printf("la altura de la rama es: %d\n",alt); 
    }
    
    
}

void listar_nodos_mismo_nivel_int(NodoArbol nodo, int nivel_actual, int nivel_deseado) {
    if (nodo == NULL) {
        return;
    }
    
    if (nivel_actual == nivel_deseado) {
        printf("%d ", nodo->datos->clave);
    }
    
    // Recorrer los subárboles recursivamente
    listar_nodos_mismo_nivel_int(nodo->hi, nivel_actual + 1, nivel_deseado);
    listar_nodos_mismo_nivel_int(nodo->hd, nivel_actual + 1, nivel_deseado);
}

void listar_nodos_mismo_nivel(NodoArbol nodo,int nivel_actual,int clave){
    int i;
    i=a_nivel(nodo,clave);
    if(i!=-1){
        listar_nodos_mismo_nivel_int(nodo,nivel_actual,i);   
    }
    
}

int main() {
    ArbolBinario a;
    TipoElemento x;
    NodoArbol n;
    int clave,i;
    ingresarNumero("\ningrese el nodo: ",&clave);
    
    a=a_crear();
    cargar_arbol(a);
    a_buscar_padre(a,clave);
    a_buscar_hijos(a,clave);
    a_buscar_hermano(a,clave);
    i=a_nivel(a_raiz(a),clave);
    printf("el nivel del nodo es: %d\n",i);
    obtener_altura_rama(a,clave);
    printf("nodos del mismo nivel:\n");
    listar_nodos_mismo_nivel(a_raiz(a),0,clave);
}
