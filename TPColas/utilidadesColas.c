#include "utilidadesColas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void intercambiar(Cola cola,Cola Caux){
TipoElemento X;
while (c_es_vacia(Caux) != true) {
    X = c_desencolar(Caux);
    c_encolar(cola, X);
}
}

void c_cargar(Cola cola, int cantidad){
    TipoElemento clave;
    int i = 0;
    while (!c_es_llena(cola) && i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave a encolar: ");
        scanf("%d", &clave->clave);
        c_encolar(cola, clave);
        i++;
    }
}

int c_longitud(Cola cola){
int i;
Cola caux;
caux=c_crear();
i=0;
TipoElemento x;
while(!c_es_vacia(cola)){
	x=c_desencolar(cola);
	c_encolar(caux,x);
	i=i+1;
}
c_intercambiar(cola,caux);
return i;
}

bool c_buscar_clave (Cola cola, int n){
	Cola Caux = c_crear();
	TipoElemento te;
	bool resultado = false;

    // ciclo que mueve los elementos a la cola auxiliar, similar a un p_intercambiar
	while (!c_es_vacia(cola)) {
		te = c_desencolar(cola);
		c_encolar(Caux, te);
    
		// condicional que se encontro el elemento buscado
		if (te->clave == n){
			resultado = true;
    	}
	}
	
	// recupero los elementos de la cola auxiliar a la original y la dejo como estaba
	c_intercambiar (cola, Caux);

	return resultado;    
}

int c_buscar_posicion (Cola cola, int n){
	Cola Caux = c_crear();
	TipoElemento te;
	int i=1;
	int resultado=-1;
    // ciclo que mueve los elementos a la cola auxiliar, similar a un p_intercambiar
	while (!c_es_vacia(cola)) {
		te = c_desencolar(cola);
		c_encolar(Caux, te);
    
		// condicional que se encontro el elemento buscado
		if (te->clave == n){
			resultado = i;
    	}
		i++;
	}
	
	// recupero los elementos de la cola auxiliar a la original y la dejo como estaba
	c_intercambiar (cola, Caux);

	return resultado;    
}

Cola c_duplicar(Cola cola){
    TipoElemento clave;
    int longitud;
    longitud=c_longitud(cola);
    Cola caux ,caux2;
    caux=c_crear();
    caux2=c_crear();
    while(!c_es_vacia(cola)){
        clave=c_desencolar(cola);
        c_encolar(caux,clave);
        c_encolar(caux2,clave);
    }
    c_intercambiar(cola,caux);
    c_intercambiar(caux,caux2);
    return caux;
}

bool c_tiene_repetidos(Cola cola){
    TipoElemento clave;
    Cola caux;
    bool res,bandera;
	bandera=false;
    caux=c_crear();
    while(!c_es_vacia(cola)){
        clave=c_desencolar(cola);
        c_encolar(caux,clave);
        res=c_buscar_clave(cola,clave->clave);
		if(res){
			bandera=true;
		}
    }
    c_intercambiar(cola,caux);
    return bandera;
}

void c_cargar_no_repetidos(Cola cola, int cantidad){
    TipoElemento clave;
    int i = 0;
    bool encontrado;
    if(cantidad<=TAMANIO_MAXIMO){
      while (!c_es_llena(cola) && i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave a encolar: ");
        scanf("%d", &clave->clave);
        encontrado=c_buscar_clave(cola,clave->clave);
        if(!encontrado){
            c_encolar(cola, clave);
            i++;  
        }else{
            printf("no puede ingresar elementos repetidos\n");
        }
        
    }  
    }else{
        printf("no se puede cargar mas elementos que el tamaño maximo\n");
    }
    
}

void c_cargar_mayores_no_rep(Cola cola, int cantidad,int limite){
    TipoElemento clave;
    int i = 0;
    bool encontrado;
    if(cantidad<=TAMANIO_MAXIMO){
      while (!c_es_llena(cola) && i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave a encolar: ");
        scanf("%d", &clave->clave);
        encontrado=c_buscar_clave(cola,clave->clave);
        if(!encontrado&&clave->clave>limite){
            c_encolar(cola, clave);
            i++;  
        }else{
            printf("no puede ingresar elementos repetidos o menores a 2\n");
        }
        
    }  
    }else{
        printf("no se puede cargar mas elementos que el tamaño maximo\n");
    }
    
}
