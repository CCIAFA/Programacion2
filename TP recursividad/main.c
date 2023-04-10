#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "valida.h"
#include "TP_Recursividad.c"

/*
  Aca se encuentran definidos los prototipos y los codigos de las funciones del main.
  El codigo de llamada e ingreso de datos para las funciones del TP se encuentran 
  separado en procedimientos para que sea mas sencillo el intercambio de codigo.
  Tambien se encuentra definida la funcion "menu" que imprime el menu en pantalla, 
  pide el ingreso de una opcion.  
*/

int menu();
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();

int main()
{
    int opcion;
	do
	{
		opcion = menu();
		
		switch (opcion)
		{
			case 'a':
				system("cls");
				ejercicio1();
				printf("\n\n");
				system("Pause");
				break;
			case 'b':
				system("cls");
				ejercicio2();
				printf("\n\n");
				system("Pause");
				break;
			case 'c':
				system("cls");
				ejercicio3();
				printf("\n\n");
				system("Pause");
				break;
			case 'd':
				system("cls");
				ejercicio4();
				printf("\n\n");
				system("Pause");
				break;
			case 'e':
				system("cls");
				ejercicio5();
				printf("\n\n");
				system("Pause");
				break;
			case 'f':
				system("cls");
				ejercicio6();
				printf("\n\n");
				system("Pause");
				break;
			case 'g':
				system("cls");
				ejercicio7();
				printf("\n\n");
				system("Pause");
				break;
			case 'h':
				system("cls");
				ejercicio8();
				printf("\n\n");
				system("Pause");
				break;
			case 'i':
				system("cls");
				ejercicio9();
				printf("\n\n");
				system("Pause");
				break;
			case 'j':
				system("cls");
				ejercicio10();
				printf("\n\n");
				system("Pause");
				break;
			case 'q':
				break;
			default:
				printf("\nOpcion incorrecta!");
				printf("\nPresione [ENTER] para continuar");
				getche();
				break;
		}
	} while (opcion != 'q');
	
	printf("\n\nPrograma Finalizado.\n\n");
	system("pause");
	return 0;
}

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
	
	char texto[MAX_CARACTERES];
	printf("\nIngrese un palindromo:");
	ingresarCadena(texto);
	
	//char textoSinEspacios[100];
	//memset(textoSinEspacios, 0, sizeof(textoSinEspacios));
	//eliminaEspacios(texto, textoSinEspacios);
	
	if (palindromo(texto)){
		printf("\nEs un palindromo!");
	}
	else {
		printf("\nNo es un palindromo!");
	}
}

void ejercicio2(){
	
	int n1, n2;
	
	printf("Ingrese numeros menores a 44.000 y mayores a -44.000\n\n");
	n1= ingresarNumeroEntre("\nIngrese un numero:", -44000,44000);
	n2= ingresarNumeroEntre("\nIngrese un segundo numero:", -44000,44000);
	
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
	ingresarNumeroSin0("\nIngrese el divisor:", &n2);
	
    result = division(n1,n2);
    printf("%f", result); 
    //printf("\n %.10f",m/n);
}

void ejercicio5(){
	
	char cadena[MAX_CARACTERES]="";
	char respuesta[MAX_CARACTERES] ="";
	
    printf("\nIntroduce un numero: ");
    cadenaDeNumeros(cadena);
	agregarSeparadorMiles(cadena,respuesta);
	
    printf("\nResultado: %s \n", respuesta);
}

void ejercicio6(){
	int n;
	
    n = ingresarNumeroEntre("\nIntroduce el nivel a mostrar [1-50]: ",1,MAX_NIVEL_MAFIA);
    
	printf("%s",vistaFrontalNivel(n));
}

void ejercicio7(){
    char cadena[MAX_CARACTERES];

    printf("\nIntroduce una cadena de texto: ");
    ingresarOndaDigital(cadena);

    printf("\nResultado de la onda digital: %s",ondaDigital(cadena));
    
    free(cadena);
}

void ejercicio8(){
	/*  PRUEBA
	
	int lista[6] = {10,3,1,7,4,2};
	mostrarSubconjuntoEnPantalla(lista,5);
	printf("- %d \n",sumaSubconjunto(lista,5));
	int lenLista = sizeof(lista)/sizeof(int);
	subconjuntosQueSumanN(lista,lenLista,7);*/
	
	printf("Ingrese una lista de numeros separados por coma: ");
	char listaDeNumeros[MAX_LISTA];
	fflush(stdin);
	gets(listaDeNumeros);
	
	int listaDeEnteros[MAX_LISTA_NUMEROS];
	int len = separarEnteros(listaDeNumeros,listaDeEnteros);
	
	int suma;
	ingresarNumero("Ingrese el valor de la suma: ", &suma);	
	
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
	ingresarNumeroMayor("\nIngrese un numero:", &n1,0);
	ingresarNumeroMayor("\nIngrese la bomba (mayor a 1): ", &n2,1);	
	int *resultado = explosion(n1,n2);
	printf("\nResultado :");
	//mostrarResultadoEnLista(resultado);
	mostrarResultadoEnLista(resultado,0);
	free(resultado);
} 

