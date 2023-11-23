/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// Función para calcular el factorial de un número
unsigned long long calcularFactorial(int numero) {
    unsigned long long factorial = 1;
    
    if (numero < 0) {
        printf("No se puede calcular el factorial de un número negativo.\n");
        return 0;
    }

    for (int i = 1; i <= numero; i++) {
        factorial *= i;
    }

    return factorial;
}

int main() {
    int numero;
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &numero);

    unsigned long long factorial = calcularFactorial(numero);

    if (factorial != 0) {
        printf("El factorial de %d es %llu\n", numero, factorial);
    }

    return 0;
}

