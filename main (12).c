/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define FILE_NAME "datos.txt"

typedef struct {
    int id;
    char name[MAX_LEN];
} Data;

void crear();
void cargar(Data data[], int *size);
void listar(Data data[], int size);
void consultar(Data data[], int size);
void modificar(Data data[], int size);

int main() {
    int option;
    Data data[MAX_LEN];
    int size = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Crear\n");
        printf("2. Cargar\n");
        printf("3. Listar\n");
        printf("4. Consultar\n");
        printf("5. Modificar\n");
        printf("6. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);
        while (getchar() != '\n'); // Limpia el buffer de entrada

        switch (option) {
            case 1: crear(); break;
            case 2: cargar(data, &size); break;
            case 3: listar(data, size); break;
            case 4: consultar(data, size); break;
            case 5: modificar(data, size); break;
            case 6: exit(0); // Salir del programa
            default: printf("Opción no válida.\n"); break;
        }
    }
    return 0;
}

void crear() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Error al abrir el archivo");
        return;
    }
    Data newData;
    printf("Ingrese ID: ");
    scanf("%d", &newData.id);
    while (getchar() != '\n'); // Limpia el buffer de entrada
    printf("Ingrese nombre: ");
    fgets(newData.name, MAX_LEN, stdin);
    size_t len = strlen(newData.name);
    if (len > 0 && newData.name[len-1] == '\n') {
        newData.name[len-1] = '\0'; // Remueve el newline al final
    }
    fprintf(file, "%d,%s\n", newData.id, newData.name);
    fclose(file);
}

void cargar(Data data[], int *size) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return;
    }
    *size = 0;
    while (fscanf(file, "%d,%99[^\n]", &data[*size].id, data[*size].name) != EOF) {
        (*size)++;
    }
    fclose(file);
}

void listar(Data data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Nombre: %s\n", data[i].id, data[i].name);
    }
}

void consultar(Data data[], int size) {
    int id;
    printf("Ingrese ID para consultar: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (data[i].id == id) {
            printf("ID: %d, Nombre: %s\n", data[i].id, data[i].name);
            return;
        }
    }
    printf("ID no encontrado.\n");
}

void modificar(Data data[], int size) {
    int id;
    printf("Ingrese ID para modificar: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (data[i].id == id) {
            printf("ID encontrado. Ingrese nuevo nombre: ");
            while (getchar() != '\n'); // Limpia el buffer de entrada
            fgets(data[i].name, MAX_LEN, stdin);
            size_t len = strlen(data[i].name);
            if (len > 0 && data[i].name[len-1] == '\n') {
                data[i].name[len-1] = '\0'; // Remueve el newline al final
            }
            // Recreamos el archivo para actualizarlo con los nuevos datos
            FILE *file = fopen(FILE_NAME, "w");
            if (!file) {
                perror("Error al abrir el archivo");
                return;
            }
            for (int j = 0; j < size; j++) {
                fprintf(file, "%d,%s\n", data[j].id, data[j].name);
            }
            fclose(file);
            printf("Nombre modificado.\n");
            return;
        }
    }
    printf("ID no encontrado.\n");
}
