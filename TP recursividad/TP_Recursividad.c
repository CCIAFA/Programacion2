#include "TP_Recursividad.h"
#include "valida.h"

// Ejercicio 1

bool esPalindromo(char *palabra, int inicio, int fin){
/*
  Recibe una cadena, el inicio de la cadena para iniciar la busqueda y el final.
  La funcion va comparando el inicio y el final de la palabra, si estos son iguales
  es indicio de que puede llegar a ser un palindromo. Y asi hasta llegar al centro
  de la palabra, si esto se cumple es decir la palabra es un palindromo, en cambio
  si en algun momento una comparacion no es igual automaticamente retorna falso.
*/
    if (inicio >= fin){
        return true;
    }
    else if (palabra[inicio] == palabra[fin]){
        return esPalindromo(palabra, inicio + 1, fin - 1); 
    }
    else{
        return false;
    }
}

bool palindromo(char* palabra){
/*
  Funcion para llamar a la funcion recursiva, solo recive la palabra y le agrega
  el inicio en 0 y el tamaño de la cadena.
*/
     int finPalabra = strlen(palabra);
     return esPalindromo(palabra,0,finPalabra-1);
}

// Ejercicio 2

long producto(long a, long b){
/*
  Recibe dos numeros, realiza la multiplicacion mediante sumas sucesivas del numero a
  tantas veces como lo indica b. En el caso que b llegue a cero indica el final de la 
  operacion y retorna 0, en cambio si b es mayor a cero se realiza la suma y se vuelve
  a llamar la funcion restandole uno a b. 
  Como la funcion se realiza restandole a b, si b es negativo entraria en un loop infinito,
  entonces ante este caso se invierten  los signos de ambos numeros, a y b, para conservar 
  el signo del resultado.
*/
	if (b == 0){
        return 0; 
    }
    else if (b > 0){
        return a + producto(a, b - 1); 
    }
    else {
    	a = -a;
    	b = -b;
    	return producto(a, b);
	}
}    

// Ejercicio 3

long terminoSerieFibonacci (int n) {
    if (n == 0) {
        return 0;
    } 
    else if (n == 1) {
        return 1;
    } 
	else {
        return (terminoSerieFibonacci(n-1) + terminoSerieFibonacci(n-2));
    }
}

// Ejercicio 4

float division2(float m, float n, int d, float r) {
//m = dividendo; n = divisor, d = num. de decimales, r = el valor a sumar al resultado

	if (d == -1) {
    // Este caso se da cuando se terminan de calcular los decimales. 
    	return 0;
    }
    if (n == m) {
    // Caso base cuando la divicion es exacta.
        return r ;
    }
     if (n > m) {
     // Si el resto es menor al divisor, entonces se divide por 10 el divisor y el r
     // para continuar la division y calcular la parte decimal. 
        return division2(m,n/10,d-1,r/10);
    }
    if (n<m){
    // Caso recursivo donde se le va sumando r al resultando indicando que se realizo la resta.
        return r + division2(m - n, n,d,r);
    }
    
}

float division(float m, float n){
/*
  Funcion para llamar a la recursiva division2, le agrega los parametros de DECIMALES
  y INCREMENTO, que es el valor que le va sumando al resultado cuando se realiza una 
  resta.
*/
	int signo = 1;
	if ((m<0 && n>0)||(m>0 && n<0)){
    // If para determinar el signo del resultado, ya que la division se realiza con 
    // numeros positivos. La condicion es un XOR. 
		signo = -1;
	}
	return signo*division2(abs(m),abs(n),DECIMALES,INCREMENTO);
}

// Ejercicio 5

void agregarSeparadorMiles(char* numero, char* destino) {
/*
  Se ingresan dos string, "numero" con la cadena de numero a procesar y 
  la cadena "destino" donde se guardara el numero separado por puntos.
*/
	int len = strlen(numero);
    if (len < 4) {
    // Si la cadena es menor a 4, no necesita separador.
        strcat(destino, numero);
    } else if (len%3 != 0) {
    // Si el numero de elementos en la cadena no es multiplo de 3, entonces esta 
    // linea separa los primeros digitos para colocar el primer separador y luego 
    // vuelve a llamar a la funcion.
    		strncat(destino, numero, len%3);
    		strcat(destino, ".");
    		agregarSeparadorMiles(numero+(len%3),destino);
    	} else {
     // Una vez que el numero de elementos es multiplo de 3, separa 3 digitos para 
     // concatenar a la cadena destino y volver a llamar a la funcion. 
	    	strncat(destino, numero, 3);
	    	strcat(destino, ".");
	    	agregarSeparadorMiles(numero+3, destino);
    }
}

// Ejercicio 6

void crearVistaFrontalNivel(int n, char* cadena) {
/*
  Esta funcion recursiva recibe: "n": nivel a mostar, "cadena": arreglo donde se guarda
  los caracteres de la vista frontal de la mafia china.
*/
	strcat(cadena,"(-.");
	//Concatena la media cara inicial de la mitad izquierda
    n--;
    if (n == 0) {
    // Si n es 0, quiere decir que llego al centro y cierra la cara central.
   	    strcat(cadena,"-)");
        return;
    }
    crearVistaFrontalNivel(n,cadena);
    // Vuelve a llamar la funcion hasta completar la mitad izquierda.
    strcat(cadena,".-)");
    // Una vez completada la cara central, comienza a colocar las caras de la mitad
    // derecha, en esta linea que queda pendiente de los llamados anteriores de la funcion.
}

char* vistaFrontalNivel(int nivel){
/*
  Funcion que llama a la fn recursiva, crea la cadena destino para luego retornarla.
*/
      char* cadena = malloc(310);
      memset(cadena,0,sizeof(char));
      crearVistaFrontalNivel(nivel,cadena);
      return cadena;
}

// Ejercicio 7

void ondaDigitalRecursiva(char *cadena, char* resultado) {
// Esta funcion recibe la cadena de "l" y "h", y la cadena "resultado" para guardar
// el dibujo de la onda.
    if (strlen(cadena) == 0) {
    // Si el tamaño de la cadena es 0, llego al final y termina la funcion.
        return;
    } else {
        if (cadena[0] == 'l') {
        // Si el primer elemento es una "l" concatena un guion bajo al resultado.
            strcat(resultado,"_");
        } else if (cadena[0] == 'h') {
        // Creo una cadena con el caracter del guion alto para luego concatenar al resultado.
            char guionAlto[3];
            sprintf(guionAlto,"%c",238);
            // ASCII 238 = guion alto
            strcat(resultado,guionAlto);
        } 
        if (strlen(cadena)>1){
        // Aca se consulta si la cadena es mayor a 1 para consultar si el siguiente caracter 
        // es distinto al actual para concatenar el pipe que indica el cambio de estado logico.
        	if (cadena[0]!=cadena[1]){
        		strcat(resultado,"|");
        	}
        }
        ondaDigitalRecursiva(cadena+1,resultado);
        // Se vuelve a llamar la funcion corriendo un lugar el inicio.
    }
}

char* ondaDigital(char* cadenaOnda){
/*
  Funcion que llama la fn recursiva. Se crea la cadena resultado y luego la retorna.
*/
      char* cadenaResultado = malloc(200);
      memset(cadenaResultado,0,sizeof(char));
      ondaDigitalRecursiva(cadenaOnda,cadenaResultado);
      return cadenaResultado;
}

// Ejercicio 8

void encontrarSubconjuntosQueSumanN(int lista[], int suma, int subconjunto[], int inicio, int fin, int finSubconjunto){
/*
  La funcion recibe: el arreglo de enteros "lista[]" , que es el conjunto de numeros.
                     el entero "suma", el valor que tienen que sumar los elementos de los subconjuntos.
                     el arreglo "subconjunto[], que es donde se van guardando los elementos del subconjunto armado.
                     el entero "inicio", indica el inicio de donde se tiene que procesar "lista[]".
                     el entero "fin", indica el fin de la cadena "lista[]".
                     el entero "finSubconjunto", indica el tamaño del arreglo de enteros "subconjuntos[]".
  La funcion basicamente busca todas las conbinaciones de subconjuntos y evalua los que la suma de sus elementos
  es igual a "suma", si es asi muestra el subconjunto en pantalla.
*/
	if (inicio == fin){
		if(sumaSubconjunto(subconjunto,finSubconjunto) == suma){
			mostrarSubconjuntoEnPantalla(subconjunto,finSubconjunto);
		}
		return;
	} else {
    	encontrarSubconjuntosQueSumanN(lista,suma,subconjunto,inicio+1,fin,finSubconjunto);
    	subconjunto[finSubconjunto+1]=lista[inicio];
    	encontrarSubconjuntosQueSumanN(lista,suma,subconjunto,inicio+1,fin,finSubconjunto+1);
    }
}

int sumaSubconjunto(int subconjunto[], int finSubconjunto) {
/*
  Funcion recursiva que recibe el arreglo "subconjunto" y su tamaño "finSubconjunto" y 
  retorna el valor de la suma de sus elementos.
*/
    if (finSubconjunto == -1) {
        return 0;
    }
    return subconjunto[finSubconjunto] + sumaSubconjunto(subconjunto, finSubconjunto - 1);
}

void subconjuntosQueSumanN(int lista[], int tamLista, int suma) {
/*
  Funcion que llama a la fn recursica, se agregan los parametros del arreglo de enteros
  "subconjuntos", el inicio 0 y el tamaño del subconjunto en -1 para que cuando se agregue
  el primer elemento quede con el indice 0.
*/
    int subconjunto[tamLista];
    encontrarSubconjuntosQueSumanN(lista, suma, subconjunto, 0, tamLista , -1);
}

// Ejercicio 9

bool divisiblePor7(long n){
/*
  Indica si el numero ingresado "n" es multiplo de 7.
*/
	//Si el numero es negativo para entrar a la funcion recursiva se toma el valor absoluto.
    if (n<0) divisiblePor7(abs(n));
    int aux;
	if(n<=70){
    // si n es menor a 70, se pregunta si el resto de su division por 7 es 0,
    // es decir si es divisible por 7 y retorna ese valor logico.
		return (n % 7 == 0);
	} else {
    // si no es menor a 70, le quita el ultimo digito al numero y a lo que queda
    // le resta el doble de ese digito y vuelve a llamar la funcion con el resultado.
		aux = n % 10;
		n = ((n-aux)/10) - 2*aux;
		divisiblePor7(n);
	}
}

// Ejercicio 10

void explotaEn(int numero, int bomba, int* resultado, int* i){
	int n1,n2;
	if (numero<=bomba){
    // Si el numero es menor o igual a la bomba  lo guardo en la cadena resultado 
    // y guardo el tamaño del arreglo en la posicion 0.
        (*i)++;               
		resultado[*i]= numero;
		resultado[0]= *i;
	} else {
    // se realizan las operaciones matematicas para ver en los numeros que explota la bomba
		//n1 = division2(numero,bomba,0,1);
		n1 = divisionEntera(numero,bomba);
		n2 = numero - n1;
		// Se llama a la funcion con los valores de los resultados de la explosion.
		explotaEn(n1,bomba, resultado, i);
		explotaEn(n2,bomba, resultado, i);
	}
}

int* explosion(int numero, int bomba){
/*
  Funcion que llama la fn recursiva, crea el arreglo de enteros "resultado" y el "indice"
  que es el tamaño de la variable "resultado" para realizar el llamado.
  En la posicion 0 de "resultado" se guarda el tamaño de este.
*/
    int *resultado = (int *)malloc(sizeof(int) * 100);
    int indice = 0;
    explotaEn(numero,bomba,resultado, &indice);
	return resultado;
}
