#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "valida.h"
#include "TP_Recursividad.h"

int menu()
{
	system("cls");
	printf("---------------------------------------------------------------------");	
	printf("\n T.P. Recursividad ");
	printf("\n---------------------------------------------------------------------");
	printf("\n a - Palindromo");
	printf("\n b - Producto");
	printf("\n c - Serie de Fibonacci");
	printf("\n d - Division");
	printf("\n e - Separador de miles");
	printf("\n f - Vista frontal del nivel de la mafia");
	printf("\n g - Onda digital");
	printf("\n h - Subconjuntos que suman N");
	printf("\n i - Divisible por 7");
	printf("\n j - Explosion");
	printf("\n\n q - Salir");
	printf("\n---------------------------------------------------------------------");
	printf("\n Ingrese una opcion: ");
		
	return getche();
}

void ejercicio1(){
	
	char texto[100];
	char textoSinEspacios[100];
	
	memset(textoSinEspacios, 0, sizeof(textoSinEspacios));
	
	printf("\nIngrese un palindromo:");
	
	ingresarCadena(texto);
	//eliminaEspacios(texto, textoSinEspacios);
	
	if (palindromo(textoSinEspacios,0,strlen(textoSinEspacios)-1)){
		printf("\nEs un palindromo!");
	}
	else {
		printf("\nNo es un palindromo!");
	}
}

void ejercicio2(){
	
	int n1, n2;
	
	ingresarNumero("\nIngrese un numero:", &n1);
	ingresarNumero("\nIngrese un segundo numero:", &n2);
	
	printf("\nResultado : %d",producto(n1,n2));
}

void ejercicio3(){
	
	int n1;
	
	n1 = ingresarNumeroEntre("\nIngrese un numero [1-40]:",1,40);
	
	printf("\nTermino %d de la serie de Fibonacci: %d",n1,terminoSerieFibonacci(n1));
}

void ejercicio4(){
	
	double result = 0;
	int n1,n2;
	
	ingresarNumero("\nIngrese el dividendo:", &n1);
	ingresarNumero("\nIngrese el divisor:", &n2);
	
    result = division(n1,n2);
    printf("%f", result); 
    //printf("\n %.10f",m/n);
}

void ejercicio5(){
	
	char cadena[100]="";
	char respuesta[100] ="";
	
    printf("\nIntroduce un numero: ");
    cadenaDeNumeros(cadena);
	agregarSeparadorMiles(cadena,respuesta);
	
    printf("\nResultado: %s \n", respuesta);
}

void ejercicio6(){
	int n;
	
    n = ingresarNumeroEntre("\nIntroduce el nivel a mostrar [1-40]: ",1,40);
    
	vistaFrontalNivel(n);
}

void ejercicio7(){
	 char cadena[100];

    printf("\nIntroduce una cadena de texto: ");
    ingresarOndaDigital(cadena);

    printf("\nResultado de la onda digital: ");
    ondaDigital(cadena);
}

void ejercicio8(){
	/*  PRUEBA
	
	int lista[6] = {10,3,1,7,4,2};
	mostrarSubconjuntoEnPantalla(lista,5);
	printf("- %d \n",sumaSubconjunto(lista,5));
	int lenLista = sizeof(lista)/sizeof(int);
	subconjuntosQueSumanN(lista,lenLista,7);*/
	
	printf("Ingrese una lista de numeros separados por coma: ");
	char listaDeNumeros[300];
	fflush(stdin);
	gets(listaDeNumeros);
	
	int suma;
	ingresarNumero("Ingrese el valor de la suma: ", &suma);
	
	int listaDeEnteros[50];
	int len = separarEnteros(listaDeNumeros,listaDeEnteros);
	
	printf("\nCantidad de numeros ingresados: %d.\n",len);
	
	subconjuntosQueSumanN(listaDeEnteros,len,suma);
	
}

void ejercicio9(){
	int n;
    ingresarNumero("\nIntroduce un numero: ", &n);
    if (divisiblePor7(n)){
		printf("\nEs un divisible por 7!");
	}
	else {
		printf("\nNo es divisible por 7!");
	}
}

void ejercicio10(){
	int n1, n2;
	ingresarNumero("\nIngrese un numero:", &n1);
	ingresarNumero("\nIngrese la bomba:", &n2);
	printf("\nResultado : ");
	int *resultado = explosion(n1,n2);
	mostrarResultadoEnLista(resultado);
	free(resultado);
} 
