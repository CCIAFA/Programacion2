#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "punto10.h"
#include "valida.h"
#include "arbol-binario-busqueda.c"
#include "arbol-avl.c"
#include "arbol-binario.c"
#include "Tipo_Elemento.c"
#include "nodo.c"
#include "utilidadesArboles.c"
#include "validaciones.c"



void cargarSeriesEnArboles(int n,int rango_maximo,int tamanio) {
    ArbolAVL avl ;
    ArbolBinarioBusqueda abb;
    TipoElemento x,x2;
    int i,j,acumuladorABB,acumuladorAVL,hminABB,hmaxABB,hminAVL,hmaxAVL,llenar;
    acumuladorABB=0;
    acumuladorAVL=0;
    hmaxABB=-1;
    hmaxAVL=-1;
    hminABB=200;
    hminAVL=200;
    
    for(j=0;j<n;j++){
        //creo los arboles por cada iteracion
        avl=avl_crear();
        abb=abb_crear();
        
        //hago la insercion de datos a los arboles
        while(abb_cantidad_elementos(abb)<tamanio) {
            int numero = rand() % rango_maximo+1; // Genera números aleatorios entre 0 y rango_maximo
            x=te_crear(numero);
            //busca si la clave esta en el arbol
            x2=abb_buscar(abb,x->clave);
            //si no se encuentra la clave se la añade a los arboles
            if(x2==NULL){
                // Cargar en árbol binario de búsqueda
                abb_insertar(abb, x);
                // Cargar en árbol AVL
                avl_insertar(avl, x);
                  
            }
            
        }
        int alturaABB = abb_altura(abb);
        int alturaAVL = avl_altura(avl);
        //acumulo las alturas
        acumuladorABB=acumuladorABB + alturaABB;
        acumuladorAVL=acumuladorAVL+ alturaAVL;
        //guardo el minimo del arbol de busqueda
        if(alturaABB<hminABB){
            hminABB=alturaABB;
        }
        //guardo el maximo del arbol de busqueda
        if(alturaABB>hmaxABB){
            hmaxABB=alturaABB;
        }
        //guardo el minimo del arbol avl
        if(alturaAVL<hminAVL){
            hminAVL=alturaAVL;
        }
        //guardo el maximo del arbol avl
        if(alturaAVL>hmaxAVL){
            hmaxAVL=alturaAVL;
        }
        printf("Altura del árbol binario de búsqueda: %d\n", alturaABB);
        printf("Altura del árbol AVL: %d\n", alturaAVL);
        
    }
    printf("cantidad de claves en los arboles: %d\n",abb_cantidad_elementos(abb));
    printf("---------------------------------------------------\n");
    printf("el minimo del arbol binario de busqueda es %d\n",hminABB);
    printf("el minimo del arbol avl es %d\n",hminAVL);
    printf("el maximo del arbol binario de busqueda es %d\n",hmaxABB);
    printf("el maximo del arbol avl es %d\n",hmaxAVL);
    printf("el promedio del arbol binario de busqueda es %d\n",acumuladorABB/n);
    printf("el promedio del arbol avl es %d\n",acumuladorAVL/n);
}

// Función principal
int main() {
    int n,rango,tamanio;
    ingresarNumero("\ningrese el numero de veces que va a repetir el proceso: ",&n);
    ingresarNumero("\ningrese el rango maximo para generar las claves: ",&rango);
    ingresarNumero("\ningrese el tamaño de los arboles: ",&tamanio);
    if(rango<tamanio){
        printf("el rango debe ser mayor al tamaño de los arboles\n");
    }else{
        cargarSeriesEnArboles(n,rango,tamanio); 
    }
    
    
    
}

/*
Se puede ver que al aumentar n veces progresivamente la insercion de nodos, 
el Arbol de busqueda Binario puede degenerarse y terminar con complejidad lineal dado que no se va equilibrando, 
a diferencia del AVL.
De esta forma el AVL tendra por lo general una menor altura que el binario de busqueda sin factor de equilibrio implementado.
*/


