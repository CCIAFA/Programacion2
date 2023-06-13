#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tabla_hash.h"
#include "valida.h"
#include "punto6.h"

#define TAMANO_TABLA 20

bool esFechaValida(int dia, int mes, int anio) {
    if (anio < 2020 || anio > 2023 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    int diasEnMes;
    switch (mes) {
        case 2: // Febrero
            if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
                diasEnMes = 29;
            } else {
                diasEnMes = 28;
            }
            break;
        case 4: // Abril
        case 6: // Junio
        case 9: // Septiembre
        case 11: // Noviembre
            diasEnMes = 30;
            break;
        default:
            diasEnMes = 31;
            break;
    }

    return dia <= diasEnMes;
}

int obtenerNumerosFecha(const char *fecha) {
    char numeros[11];
    int indiceNumeros = 0;

    for (int i = 0; fecha[i] != '\0'; i++) {
        if (fecha[i] >= '0' && fecha[i] <= '9') {
            numeros[indiceNumeros] = fecha[i];
            indiceNumeros++;
        }
    }

    numeros[indiceNumeros] = '\0';
    int numerosFecha = atoi(numeros);

    return numerosFecha;
}

int funcionHash(int fecha) {
    int suma = 0;
    while (fecha > 0) {
        suma += fecha % 10;
        fecha /= 10;
    }
    return suma % TAMANO_TABLA;
}

// Función para mostrar los datos de un paciente
void mostrarPacientesEnFecha(vacunado pacientes[], int cantidad) {
    printf("Pacientes:\n");
    printf("----------------------------\n");
    
    for (int i = 0; i < cantidad; i++) {
        printf("DNI: %d\n", pacientes[i].dni);
        printf("Apellido: %s\n", pacientes[i].apellido);
        printf("Nombres: %s\n", pacientes[i].nombre);
        printf("----------------------------\n");
    }
}

// Función para cargar manualmente los datos de un paciente
vacunado cargarPaciente() {
    vacunado paciente;
    bool fechaCorrecta =false;
    int fechaNum;
    bool dniCorrecto=false;

    while (!fechaCorrecta)
    {
        printf("Ingrese la fecha de vacunacion (dd/mm/aaaa): ");
        scanf("%s", paciente.fecha);   
        fechaNum = obtenerNumerosFecha(paciente.fecha);

        int dia = fechaNum / 1000000;
        int mes = (fechaNum / 10000) % 100;
        int anio = fechaNum % 10000;
        fechaCorrecta = esFechaValida(dia, mes, anio);

        if (!fechaCorrecta) {
            printf("Fecha invalida. Por favor, ingrese una fecha valida.\n");
        }
    }
    
    while(!dniCorrecto){
        ingresarNumero("Ingrese el DNI: ", &paciente.dni);
        dniCorrecto = validarNumero8Digitos(paciente.dni); 
    }
    printf("Ingrese el apellido: ");
    scanf("%s", paciente.apellido);
    printf("Ingrese los nombres: ");
    scanf("%s", paciente.nombre);
    return paciente;
}

int main() {
    // Crear la tabla hash con el tamaño y la función de hash especificados
    TablaHash tabla = th_crear(TAMANO_TABLA, funcionHash);

    // Abrir el archivo de datos de pacientes en modo de adición binaria
    FILE *archivo = fopen("vacunados.dat", "rb+");

    // Validar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char opcion;
    do {
        // Cargar los datos de un paciente
        vacunado paciente = cargarPaciente();
        int fechaNumeros;
        
        // Guardar el paciente en el archivo
        fwrite(&paciente, sizeof(vacunado), 1, archivo);

        // Crear un TipoElemento con la clave (fecha) y la posición en el archivo como valor
        fechaNumeros = obtenerNumerosFecha(paciente.fecha);
        TipoElemento te = te_crear(fechaNumeros);
        te->valor = (int*)(ftell(archivo) - sizeof(vacunado));

        // Insertar el TipoElemento en la tabla hash
        th_insertar(tabla, te);

        printf("¿Desea cargar otro paciente? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    // Cerrar el archivo
    fclose(archivo);

    // Mostrar los elementos de la tabla hash
    th_mostrar(tabla);

    char fecha[11];
    int fechaNumeros;
    
    printf("Ingrese una fecha para realizar una consulta (0 para salir): ");
    scanf("%s", fecha);

    while (strcmp(fecha, "0") != 0) {
        fechaNumeros = obtenerNumerosFecha(fecha);
        TipoElemento te = th_recuperar(tabla, fechaNumeros);

        if (te != NULL) {
            archivo = fopen("vacunados.dat", "rb");
            if (archivo != NULL) {
                // Crear un arreglo para almacenar los pacientes
                vacunado pacientes[TAMANO_TABLA];
                int cantidad = 0;

                while (!feof(archivo)) {
                // Leer un paciente del archivo
                 vacunado paciente;
        fread(&paciente, sizeof(vacunado), 1, archivo);

            if (obtenerNumerosFecha(paciente.fecha) == fechaNumeros) {
            // El paciente coincide con la fecha buscada, almacenarlo en el array
            pacientes[cantidad] = paciente;
            cantidad++;
            }
        }   

    fclose(archivo);

    if (cantidad > 0) {
        mostrarPacientesEnFecha(pacientes, cantidad);
    } else {
        printf("No se encontraron pacientes en la fecha ingresada.\n");
}
        } else {
            printf("Error al abrir el archivo.\n");
        }
    } else {
        printf("La fecha ingresada no se encontró en la tabla hash.\n");
    }

    printf("Ingrese otra fecha (0 para salir): ");
    scanf("%s", fecha);
}

    return 0;
}
