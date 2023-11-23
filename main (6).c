/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main() {
    int arreglo[] = {1, 3, 5, 4, 7};
    int n = sizeof(arreglo) / sizeof(arreglo[0]); // Calcular la cantidad de elementos en el arreglo

    // Encontrar el valor máximo en el arreglo
    int maximo = arreglo[0];
    for (int i = 1; i < n; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }

    printf("El valor máximo en el arreglo es: %d\n", maximo);

    return 0;
}

