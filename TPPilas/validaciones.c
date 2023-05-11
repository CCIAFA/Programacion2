#include "valida.h"
#include <stdlib.h>
#include "Tipo_Elemento.h"

bool validaRango(int numero, int nInf, int nSup){
	return (numero >= nInf && numero <= nSup);
}

int esNumero(char* cadena){
   int i;  
   for(i = 0; cadena[i]; i++){ 
      if(isdigit(cadena[i])== 0){
         return 0;
      }
   }
   return 1;
}

void ingresarNumero(char* texto, int* numero){
	printf("%s",texto);
	int aux = scanf("%d", numero);
	while(aux != 1){
		printf("\nError! No se ha ingresado un numero.");
		printf("\n%s", texto);
		fflush(stdin);
		aux = scanf("%d", numero);
	}
}

void ingresarNumeroSin0(char* texto, int* numero){
	printf("%s",texto);
	int aux = scanf("%d", numero);
	while(aux != 1||*numero==0){
		printf("\nError! El caracter ingresado no es valido.");
		printf("\n%s", texto);
		fflush(stdin);
		aux = scanf("%d", numero);
	}
}

void ingresarNumeroMayor(char* texto, int* numero,int limite){
	printf("%s",texto);
	int aux = scanf("%d", numero);
	while(aux != 1 || *numero <= limite){
		printf("\nError! No se ha ingresado un numero o caracter valido.");
		printf("\n%s", texto);
		fflush(stdin);
		aux = scanf("%d", numero);
	}
}

void ingresarNumeroMenor(char* texto, int* numero,int limite){
	printf("%s",texto);
	int aux = scanf("%d", numero);
	while(aux != 1 || *numero >= limite){
		printf("\nError! No se ha ingresado un numero o caracter valido.");
		printf("\n%s", texto);
		fflush(stdin);
		aux = scanf("%d", numero);
	}
}

/* void ingresarNumero(char* texto, float* numero){
	printf("%s",texto);
	int aux = scanf("%f", numero);
	while(aux != 1){
		printf("\nError! No se ha ingresado un numero.");
		printf("\n%s", texto);
		fflush(stdin);
		aux = scanf("%f", numero);
	}
} */

int ingresarNumeroEntre(char* texto, int nInf, int nSup){
	int numero;
	ingresarNumero(texto, &numero);
	while (!validaRango(numero,nInf,nSup)){
		printf("\n ERROR! El numero esta fuera del rango aceptado.\n");
		ingresarNumero(texto, &numero);
	}
	return numero;
}


bool cadenaVacia( char *cadena){
	return (cadena[0] == '\0');
}

void ingresarCadena(char *cadena){
	fflush(stdin);
	gets(cadena);
	while (cadenaVacia(cadena)){
		printf("\n ERROR! Ingrese una cadena que contenga caracteres.");
		fflush(stdin);
		gets(cadena);
	}
}

bool contieneEspacios(char *cadena){
	int len = strlen(cadena);
	int i;
	int resultado = false;
	for (i=0;i<len;i++){
		if (cadena[i] == ' ') {
			resultado = true;
			break;
		}
	}
	return resultado;
}

void ingresarCadenaSinEspacios(char * cadena){
	fflush(stdin);
	gets(cadena);
	while (contieneEspacios(cadena)){
		printf("\n ERROR! Ingrese una cadena sin espacios.");
		fflush(stdin);
		gets(cadena);
	}
}

void eliminaEspacios(char * cadena, char* cadenaSinEspacios){
	int i = 0,j = 0;
	while (cadena[i]!='\0'){
		if(cadena[i]!=' '){
		cadenaSinEspacios[j]=cadena[i];
		j++;
		}
		i++;
	}	
}

bool cadenaDeEspacios(char* cadena){
	int len = strlen(cadena);
	int i;
	int resultado = false;
	for (i=0;i<len;i++){
		if (cadena[i]== ' ') {
			resultado = true;
		}
	}
	return resultado;
}

void noIngresarCadenaDeEspacios(char * cadena){
	fflush(stdin);
	gets(cadena);
	while (cadenaDeEspacios(cadena)){
		printf("\n ERROR! Ingrese una cadena que no sean solo espacios.");
		fflush(stdin);
		gets(cadena);
	}
}

void pasarMinusculas(char* cadena){
	int i;
	for (i=0;i<strlen(cadena);i++){
		if (!islower(cadena[i])){
			cadena[i] = tolower(cadena[i]);
		}
	}
}

bool soloNumeros(char* cadena){
	int i;
	for (i=0;i<strlen(cadena);i++){
		if (!isdigit(cadena[i])){
			return false;
		}
	}
	return true;
}

void cadenaDeNumeros(char* cadena){
	fflush(stdin);
	gets(cadena);
	while (!soloNumeros(cadena)){
		printf("\n ERROR! Ingrese una cadena que contenga caracteres numericos: ");
		fflush(stdin);
		gets(cadena);
	}
}

void ingresarOndaDigital(char* cadena){
	int i;
	int error = 0;
	do{
		fflush(stdin);
		gets(cadena);
		pasarMinusculas(cadena);
		for (i=0;i<strlen(cadena);i++){
			if (!(cadena[i]== 'h' || cadena[i]== 'l')){
				error = 1;
				break;
			} else {
				error = 0;
			}
		}
		if (error) printf("Error! Ingrese solo 'h' o 'l'. :");
	} while (error);
}

/* void mostrarResultadoEnLista(int *lista){
  printf("[ ");
  int i; 
  for (i=1; i<=lista[0]; i++) {
    printf("%d ", lista[i]);
    }
    printf("]\n");
}
*/

void mostrarResultadoEnLista(int *lista, int inicio){
  if (inicio == 0){
    printf("[ ");
  } else if ( inicio < lista[0]){
    printf("%d, ", lista[inicio]);
  } 
  if ( inicio == lista[0]){
    printf("%d]\n", lista[inicio]);
    return;
  }
  return mostrarResultadoEnLista(lista, inicio+1);
}

void mostrarSubconjuntoEnPantalla(int* subconjunto, int finSubconjunto){
	printf(" { ");
	int i;
	for (i=0; i<=finSubconjunto; i++){
		printf("%d ", subconjunto[i]);
	}
	printf("} \n");
}

int divisionEntera(int n1, int n2){
	return ((n1-(n1%n2))/n2);
}

int separarEnteros(char* lista, int* resultado){
	int len = strlen(lista);
	int i = 0;
	char delimitador[] = ",;.: ";
	char *aux = strtok(lista, delimitador);
	if ( aux != NULL){
		while (aux != NULL){
			 if (esNumero(aux)){
			   resultado[i] = (int)strtol(aux,NULL,10);
               i++;
            } else {
               printf("%s se descarta por no ser un numero.\n",aux);
            }
			aux = strtok(NULL, delimitador);
		}
	}
	return i;
}

