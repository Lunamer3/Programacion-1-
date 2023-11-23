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
    char surname[MAX_LEN];
} Data;

void crear();
void cargar(Data data[], int *size);
void listar(Data data[], int size);
void consultar(Data data[], int size);
void modificar(Data data[], int size);
void eliminar(Data data[], int *size);

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
        printf("7. Eliminar\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);
        while (getchar() != '\n'); // Limpia el buffer de entrada

        switch (option) {
            case 1: crear(); break;
            case 2: cargar(data, &size); break;
            case 3: listar(data, size); break;
            case 4: consultar(data, size); break;
            case 5: modificar(data, size); break;
            case 6: exit(0); break; // Salir del programa
            case 7: eliminar(data, &size); break;
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

    printf("Ingrese apellidos: ");
    fgets(newData.surname, MAX_LEN, stdin);
    len = strlen(newData.surname);
    if (len > 0 && newData.surname[len-1] == '\n') {
        newData.surname[len-1] = '\0'; // Remueve el newline al final
    }

    fprintf(file, "%d,%s,%s\n", newData.id, newData.name, newData.surname);
    fclose(file);
}

void cargar(Data data[], int *size) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return;
    }
    *size = 0;
    while (fscanf(file, "%d,%99[^,],%99[^\n]", &data[*size].id, data[*size].name, data[*size].surname) != EOF) {
        (*size)++;
    }
    fclose(file);
}

void listar(Data data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Nombre: %s, Apellido: %s\n", data[i].id, data[i].name, data[i].surname);
    }
}

void consultar(Data data[], int size) {
    int id;
    printf("Ingrese ID para consultar: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // Limpia el buffer de entrada

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (data[i].id == id) {
            printf("ID: %d, Nombre: %s, Apellido: %s\n", data[i].id, data[i].name, data[i].surname);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("ID no encontrado.\n");
    }
}

void modificar(Data data[], int size) {
    int id;
    printf("Ingrese ID para modificar: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // Limpia el buffer de entrada
    int i;
    for (i = 0; i < size; i++) {
        if (data[i].id == id) {
            break;
        }
    }
    if (i == size) {
        printf("ID no encontrado.\n");
        return;
    }

    printf("ID actual: %d, Nombre actual: %s, Apellido actual: %s\n", data[i].id, data[i].name, data[i].surname);

    printf("Ingrese nuevo nombre: ");
    fgets(data[i].name, MAX_LEN, stdin);
    size_t len = strlen(data[i].name);
    if (len > 0 && data[i].name[len-1] == '\n') {
        data[i].name[len-1] = '\0'; // Remueve el newline al final
    }

    printf("Ingrese nuevos apellidos: ");
    fgets(data[i].surname, MAX_LEN, stdin);
    len = strlen(data[i].surname);
    if (len > 0 && data[i].surname[len-1] == '\n') {
        data[i].surname[len-1] = '\0'; // Remueve el newline al final
    }

    // Actualizar en el archivo
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Error al abrir el archivo");
        return;
    }
    for (int j = 0; j < size; j++) {
        fprintf(file, "%d,%s,%s\n", data[j].id, data[j].name, data[j].surname);
    }
    fclose(file);
    printf("Datos modificados con éxito.\n");
}

void eliminar(Data data[], int *size) {
    int id;
    printf("Ingrese ID para eliminar: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // Limpia el buffer de entrada

    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (data[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("ID no encontrado.\n");
        return;
    }
    for (int i = index; i < (*size) - 1; i++) {
        data[i] = data[i + 1];
    }
    (*size)--;

    // Actualizar en el archivo
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Error al abrir el archivo");
        return;
    }
    for (int i = 0; i < *size; i++) {
        fprintf(file, "%d,%s,%s\n", data[i].id, data[i].name, data[i].surname);
    }
    fclose(file);
    printf("Datos eliminados con éxito.\n");
}
