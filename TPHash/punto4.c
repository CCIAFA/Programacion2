#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabla_hash.h"
#include "valida.h"
#include "punto4.h"
#include "tabla_hash_lista_colisiones.c"
#include "listas_arreglos.c"
#include "Tipo_Elemento.c"
#include "validaciones.c"

#define TAMANO_TABLA 20

// Función de hash simple que suma los dígitos del legajo
int funcionHash(int legajo) {
    int suma = 0;
    while (legajo > 0) {
        suma += legajo % 10;
        legajo /= 10;
    }
    return suma % TAMANO_TABLA;
}

// Función para mostrar los datos de un alumno
void mostrarAlumno(Alumno alumno) {
    printf("Legajo: %d\n", alumno.legajo);
    printf("Apellido: %s\n", alumno.apellido);
    printf("Nombres: %s\n", alumno.nombres);
    printf("Domicilio: %s\n", alumno.domicilio);
    printf("Teléfono: %s\n", alumno.telefono);
    printf("----------------------------\n");
}

// Función para cargar manualmente los datos de un alumno
Alumno cargarAlumno() {
    Alumno alumno;
    bool legajoCorrecto=false;
    while(!legajoCorrecto){
        ingresarNumero("Ingrese el legajo valido: ", &alumno.legajo);
        legajoCorrecto = validarNumero6Digitos(alumno.legajo); 
    }
    

    printf("Ingrese el apellido: ");
    scanf("%s", alumno.apellido);
    printf("Ingrese los nombres: ");
    scanf("%s", alumno.nombres);
    printf("Ingrese el domicilio: ");
    scanf("%s", alumno.domicilio);
    printf("Ingrese el teléfono: ");
    scanf("%s", alumno.telefono);
    return alumno;
}

int main() {
    // Crear la tabla hash con el tamaño y la función de hash especificados
    TablaHash tabla = th_crear(TAMANO_TABLA, funcionHash);

    // Abrir el archivo de datos de alumnos en modo de escritura binaria
    FILE *archivo = fopen("alumnos.dat", "wb+");

    // Validar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Cargar manualmente los datos de los alumnos y guardarlos en el archivo y la tabla hash
    char opcion;
    do {
        // Cargar los datos de un alumno
        Alumno alumno = cargarAlumno();

        // Guardar el alumno en el archivo
        fwrite(&alumno, sizeof(Alumno), 1, archivo);

        // Crear un TipoElemento con la clave (legajo) y la posición en el archivo como valor
        TipoElemento te = te_crear(alumno.legajo);
        te->valor=(int*)(ftell(archivo) - sizeof(Alumno));

        // Insertar el TipoElemento en la tabla hash
        th_insertar(tabla, te);

        printf("¿Desea cargar otro alumno? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    // Cerrar el archivo
    fclose(archivo);

    // Mostrar los elementos de la tabla hash
    th_mostrar(tabla);

    // Consultar alumnos por legajo
    int legajoConsulta;
    printf("Ingrese un legajo para realizar una consulta (0 para salir): ");
    scanf("%d", &legajoConsulta);

    while (legajoConsulta != 0) {
        // Recuperar el TipoElemento asociado al legajo ingresado
        TipoElemento te = th_recuperar(tabla, legajoConsulta);

        if (te != NULL) {
            // Leer el registro correspondiente al legajo en el archivo
            fseek(archivo, (long int)te->valor, SEEK_SET);
            Alumno alumno;
            fread(&alumno, sizeof(Alumno), 1, archivo);

            // Mostrar los datos del alumno
            mostrarAlumno(alumno);
        } else {
            printf("El legajo ingresado no se encontró en la tabla hash.\n");
        }

        printf("Ingrese otro legajo (0 para salir): ");
        scanf("%d", &legajoConsulta);
    }


    return 0;
}