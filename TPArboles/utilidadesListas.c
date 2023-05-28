#include "utilidadesListas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


void l_mostrarTodo(Lista lista){
    int resultado,i = 0;
    TipoElemento te1;
    Iterador ite;
    ite=iterador(lista);
    
    while(hay_siguiente(ite)){
      te1=siguiente(ite);
     printf("%d-%d,", te1->clave,*(int*)te1->valor);
    }
}
