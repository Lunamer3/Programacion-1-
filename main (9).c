/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

struct Paciente {
    char nombre[50];
    char apellidoPaterno[50];
    char apellidoMaterno[50];
    int edad;
    char enfermedad[100];
    int tiempoHospital;
    float costo;
};

int main() {
    int numPacientes;
    
    printf("¿Cuántos pacientes deseas registrar? ");
    scanf("%d", &numPacientes);
    
    struct Paciente pacientes[numPacientes];
    
    for (int i = 0; i < numPacientes; i++) {
        printf("Paciente #%d\n", i + 1);
        printf("Nombre: ");
        scanf("%s", pacientes[i].nombre);
        printf("Apellido Paterno: ");
        scanf("%s", pacientes[i].apellidoPaterno);
        printf("Apellido Materno: ");
        scanf("%s", pacientes[i].apellidoMaterno);
        printf("Edad: ");
        scanf("%d", &pacientes[i].edad);
        printf("Enfermedad: ");
        scanf("%s", pacientes[i].enfermedad);
        printf("Tiempo en el hospital (en días): ");
        scanf("%d", &pacientes[i].tiempoHospital);
        printf("Costo del tratamiento: ");
        scanf("%f", &pacientes[i].costo);
    }
    
    printf("\nDatos de los pacientes:\n");
    for (int i = 0; i < numPacientes; i++) {
        printf("Paciente #%d\n", i + 1);
        printf("Nombre: %s %s %s\n", pacientes[i].nombre, pacientes[i].apellidoPaterno, pacientes[i].apellidoMaterno);
        printf("Edad: %d\n", pacientes[i].edad);
        printf("Enfermedad: %s\n", pacientes[i].enfermedad);
        printf("Tiempo en el hospital: %d días\n", pacientes[i].tiempoHospital);
        printf("Costo del tratamiento: $%.2f\n", pacientes[i].costo);
    }
    
    return 0;
}

