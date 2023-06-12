#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "punto5.h"
#include "valida.h"


#define TAMANO_TABLA 2000

int funcionHash(int clave) {
    return clave % TAMANO_TABLA;
}

void calcularTiempoEstructuras(int n,int rango_maximo,int tamanio,int numeros_buscar) {
    ArbolAVL avl;
    TablaHash tabla;
    TipoElemento x,x2;
    int i,j;
    // Variables para medir los tiempos
    clock_t tiempo_avl, tiempo_tabla;
    double tiempo_total_avl = 0, tiempo_total_tabla = 0;
   //se repite la funcion n cantidad de veces
    for(j=0;j<n;j++){
        //creo los arboles por cada iteracion
        avl=avl_crear();
        tabla=th_crear(TAMANO_TABLA, funcionHash);
        
        
        //hago la insercion de datos a las estructuras
        while(avl_cantidad_elementos(avl)<tamanio) {
            int numero = rand() % rango_maximo+1; // Genera números aleatorios entre 0 y rango_maximo
            x=te_crear(numero);
            //busca si la clave esta en el arbol
            x2=avl_buscar(avl,x->clave);
            //si no se encuentra la clave se la añade a las estructuras
            if(x2==NULL){
                // Cargar en árbol AVL
                avl_insertar(avl, x);
                th_insertar(tabla,x);
                  
            }
            
        }

        //hacer la busqueda en las estructuras y calcular su tiempo
        tiempo_avl = clock(); // Iniciar medición de tiempo para árbol AVL
        for (i = 0; i < numeros_buscar; i++) {
            int numero = rand() % rango_maximo + 1; // Genera números aleatorios entre 1 y rango_maximo
            x = te_crear(numero);
            x2 = avl_buscar(avl, x->clave);
        }
        tiempo_avl = clock() - tiempo_avl; // Calcular tiempo transcurrido para árbol AVL
        tiempo_total_avl += ((double)tiempo_avl) / CLOCKS_PER_SEC; // Acumular tiempo total
        
        tiempo_tabla = clock(); // Iniciar medición de tiempo para tabla hash
        for (i = 0; i < numeros_buscar; i++) {
            int numero = rand() % rango_maximo + 1; // Genera números aleatorios entre 1 y rango_maximo
            x = te_crear(numero);
            x2 = th_recuperar(tabla, x->clave);
        }
        tiempo_tabla = clock() - tiempo_tabla; // Calcular tiempo transcurrido para tabla hash
        tiempo_total_tabla += ((double)tiempo_tabla) / CLOCKS_PER_SEC; // Acumular tiempo total
        
    }
    
    // Calcular el tiempo promedio para cada estructura
    double tiempo_promedio_avl = tiempo_total_avl / n;
    double tiempo_promedio_tabla = tiempo_total_tabla / n;
   
    
    printf("Tiempo promedio de búsqueda en AVL: %f segundos\n", tiempo_promedio_avl);
    printf("Tiempo promedio de búsqueda en tabla hash: %f segundos\n", tiempo_promedio_tabla);
      
    
 
}

// Función principal
int main() {
    int n,rango,tamanio,buscar;
    ingresarNumero("\ningrese el numero de veces que va a repetir el proceso: ",&n);
    ingresarNumero("\ningrese el rango maximo para generar las claves: ",&rango);
    tamanio=ingresarNumeroEntre("\ningrese cuantas claves quiere generar: ",1,2000);
    ingresarNumero("\n ingrese cuantos numeros quiere buscar:",&buscar);
    if(rango<tamanio){
        printf("el rango debe ser mayor al tamaño de las estructuras\n");
    }else{
        calcularTiempoEstructuras(n,rango,tamanio,buscar); 
    }
    
    
    
}
/*
se puede concluir que al buscar mas claves la tabla hash tarda menos que el arbol avl
*/
