/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main() {
    FILE *archivo; // Declarar un puntero a FILE
    char nombreArchivo[] = "miarchivo.txt"; // Nombre del archivo que deseas crear y abrir

    // Intentar abrir el archivo en modo escritura ("w")
    archivo = fopen(nombreArchivo, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1; // Terminar el programa con un código de error
    }

    // Escribir "Guillermo Luna" en el archivo
    fprintf(archivo, "Guillermo Luna");

    // Cerrar el archivo
    fclose(archivo);

    return 0; // Terminar el programa con éxito
}
