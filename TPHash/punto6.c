#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabla_hash.h"
#include "valida.h"
#include "punto6.h"

#define TAMANO_TABLA 50

void main(){
    int opcion;
	do
	{
		opcion = menu();
		
		switch (opcion)
		{
			case '1':
				system("cls");
				cargar();
				printf("\n\n");
				system("Pause");
				break;
			case '2':
				system("cls");
				mostrar();
				printf("\n\n");
				system("Pause");
				break;
			case '0':
				break;
			default:
				printf("\nOpcion incorrecta!");
				printf("\nPresione [ENTER] para continuar");
				getchar();
                fflush(stdin);
				break;
		}
	} while (opcion != '0');
	
	printf("\n\nPrograma Finalizado.\n\n");
	system("pause");
	return 0;
}
int menu()
{
	system("cls");
	printf("---------------------------------------------------------------------");	
	printf("\n Registro vacunados por COVID ");
	printf("\n---------------------------------------------------------------------");
	printf("\n 1 - Cargar datos");
	printf("\n 2 - Mostrar datos");
	printf("\n\n 0 - Salir");
	printf("\n---------------------------------------------------------------------");
	printf("\n Ingrese una opcion: ");
		
	return getchar();
}
void cargar(){
    Fecha fecha = cargarFecha();
    Persona persona = cargarPersona();
}

Persona cargarPersona() {
    Persona persona;
    bool dniCorrecto=false;
    while(!dniCorrecto){
        ingresarNumero("Ingrese el DNI valido: ", &persona.dni);
        dniCorrecto = validarNumero8Digitos(persona.dni); 
    }

    printf("Ingrese el apellido: ");
    scanf("%s", persona.apellido);
    printf("Ingrese el nombre: ");
    scanf("%s", persona.nombre);
    return persona;
}

void mostrarPersona(Persona persona) {
    printf("DNI: %d\n", persona.dni);
    printf("Apellido: %s\n", persona.apellido);
    printf("Nombre: %s\n", persona.nombre);
    printf("----------------------------\n");
}

void mostrarFecha(Fecha fecha) {
    printf("\n%d/", fecha.dia);
    printf("%d/", fecha.mes);
    printf("%d \n", fecha.anio);
    printf("----------------------------\n");
}