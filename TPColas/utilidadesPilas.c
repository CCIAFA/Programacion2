#include "utilidadesPilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//pone el contenido de la pila auxiliar devuelta en la pila original
void p_intercambiar(Pila pila,Pila Paux){
    TipoElemento X=te_crear(0);
    while (p_es_vacia(Paux) != true) {
    X = p_desapilar(Paux);
    p_apilar(pila, X);
}
};
//recibe la pila y la cantida de elementos que se quieran ingresars
void p_cargar(Pila pila, int cantidad){
    TipoElemento clave;
    int i = 0;
    while (!p_es_llena(pila) && i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave a apilar: ");
        scanf("%d", &clave->clave);
        p_apilar(pila, clave);
        i++;
    }
}

bool p_buscar_clave (Pila pila, int n){
	Pila Paux = p_crear(Paux);
	TipoElemento te;
	bool resultado = false;

    // ciclo que mueve los elementos a la pila auxiliar, similar a un p_intercambiar
	while (!p_es_vacia(pila)) {
		te = p_desapilar(pila);
		p_apilar(Paux, te);
    
		// condicional que se encontro el elemento buscado
		if (te->clave == n){
			resultado = true;
    	}
	}
	
	// recupero los elementos de la pila auxiliar a la original y la dejo como estaba
	p_intercambiar (pila, Paux);

	return resultado;    
}

TipoElemento p_traer_clave (Pila pila, int n){
	Pila Paux = p_crear(Paux);
	TipoElemento te,resultado;
    // ciclo que mueve los elementos a la pila auxiliar, similar a un p_intercambiar
	while (!p_es_vacia(pila)) {
		te = p_desapilar(pila);
		// condicional que se encontro el elemento buscado
		if (te->clave == n){
			resultado = te;
			break;
    	}else resultado=NULL;
		p_apilar(Paux, te);//si no es el elemento buscado se apila en la pila auxiliar
	}
	// recupero los elementos de la pila auxiliar a la original y la dejo como estaba
	p_intercambiar (pila, Paux);

	return resultado;    
}

void p_mostrar_todo(Pila pila){
    if(p_es_vacia(pila)){
        printf("PILA VACIA \n");
        return;
    }
Pila Paux=p_crear();
TipoElemento X=te_crear(0);
printf("Contenido de la pila: ");

// Recorro la pila desopilándola y pasándola al auxiliar
while (p_es_vacia(pila) != true) {
    X = p_desapilar(pila);
    printf("%d-%d,", X->clave,*(int*)X->valor);
    p_apilar(Paux, X);
}
// Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
while (p_es_vacia(Paux) != true) {
    X = p_desapilar(Paux);
    p_apilar(pila, X);
}
printf("\n");
}

int p_longitud(Pila pila){
int i;
Pila paux;
paux=p_crear();
i=0;
TipoElemento x;
while(!p_es_vacia(pila)){
	x=p_desapilar(pila);
	p_apilar(paux,x);
	i=i+1;
}
p_intercambiar(pila,paux);
return i;
}

bool p_tiene_repetidos(Pila pila){
    TipoElemento clave;
    Pila paux;
    bool res,bandera;
    bandera=false;
    paux=p_crear();
    while(!p_es_vacia(pila)){
        clave=p_desapilar(pila);
        p_apilar(paux,clave);
        res=p_buscar_clave(pila,clave->clave);
        if(res){
            bandera=true;
        }
    }
    p_intercambiar(pila,paux);
    return bandera;
}

int p_buscar_posicion (Pila pila, int n){
	Pila Paux = p_crear();
	TipoElemento te;
	int i=1;
	int resultado=-1;
    // ciclo que mueve los elementos a la cola auxiliar, similar a un p_intercambiar
	while (!p_es_vacia(pila)) {
		te = p_desapilar(pila);
		p_apilar(Paux, te);
    
		// condicional que se encontro el elemento buscado
		if (te->clave == n){
			resultado = i;
    	}
		i++;
	}
	
	// recupero los elementos de la cola auxiliar a la original y la dejo como estaba
	p_intercambiar (pila, Paux);

	return resultado;    
}

void p_cargar_no_repetidos(Pila pila, int cantidad){
    TipoElemento clave;
    int i = 0;
	bool encontrado;
    while (!p_es_llena(pila) && i < cantidad) {
        clave=te_crear(0);
        printf("Ingrese la clave a apilar: ");
        scanf("%d", &clave->clave);
		encontrado=p_buscar_clave(pila,clave->clave);
		if(!encontrado){
			p_apilar(pila, clave);
        	i++;	
		}else{
			printf("no puede ingresar elementos repetidos\n");
		}
        
    }
}
