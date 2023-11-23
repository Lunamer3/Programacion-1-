/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// Definición de la estructura
struct Alumno {
    char nombre[50];
    char primerApellido[50];
    char segundoApellido[50];
    int edad;
    long long numeroCuenta;
    float promedio;
};

int main() {
    int numAlumnos, numNotas;

    printf("Ingresa la cantidad de alumnos: ");
    scanf("%d", &numAlumnos);

    printf("Ingresa la cantidad de notas por alumno: ");
    scanf("%d", &numNotas);

    // Declaración de un arreglo de estructuras para almacenar los datos de los alumnos
    struct Alumno alumnos[numAlumnos];

    for (int i = 0; i < numAlumnos; i++) {
        printf("\nDatos del Alumno %d:\n", i + 1);

        printf("Ingresa el nombre: ");
        scanf("%s", alumnos[i].nombre);

        printf("Ingresa el primer apellido: ");
        scanf("%s", alumnos[i].primerApellido);

        printf("Ingresa el segundo apellido: ");
        scanf("%s", alumnos[i].segundoApellido);

        printf("Ingresa la edad: ");
        scanf("%d", &alumnos[i].edad);

        printf("Ingresa el número de cuenta: ");
        scanf("%lld", &alumnos[i].numeroCuenta);

        float sumaNotas = 0.0;
        for (int j = 0; j < numNotas; j++) {
            float nota;
            printf("Ingresa la nota %d para el Alumno %d: ", j + 1, i + 1);
            scanf("%f", &nota);
            sumaNotas += nota;
        }
        alumnos[i].promedio = sumaNotas / numNotas;
    }

    // Mostrar la información ingresada y los promedios
    printf("\nInformación de los alumnos y promedios:\n");
    for (int i = 0; i < numAlumnos; i++) {
        printf("\nAlumno %d:\n", i + 1);
        printf("Nombre: %s %s %s\n", alumnos[i].nombre, alumnos[i].primerApellido, alumnos[i].segundoApellido);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Número de cuenta: %lld\n", alumnos[i].numeroCuenta);
        printf("Promedio de notas: %.2f\n", alumnos[i].promedio);
    }

    return 0;
}

