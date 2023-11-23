/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define N 8

// Función para imprimir el tablero
void imprimirTablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}

// Función para verificar si es seguro colocar una reina en la posición (fila, columna)
bool esSeguro(int tablero[N][N], int fila, int columna) {
    // Verificar la fila en la izquierda
    for (int i = 0; i < columna; i++) {
        if (tablero[fila][i]) {
            return false;
        }
    }

    // Verificar la diagonal superior izquierda
    for (int i = fila, j = columna; i >= 0 && j >= 0; i--, j--) {
        if (tablero[i][j]) {
            return false;
        }
    }

    // Verificar la diagonal inferior izquierda
    for (int i = fila, j = columna; i < N && j >= 0; i++, j--) {
        if (tablero[i][j]) {
            return false;
        }
    }

    return true;
}

// Función para verificar si el tablero dado es una solución válida
bool esSolucionValida(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] && !esSeguro(tablero, i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int tablero[N][N] = {0}; // Inicializar el tablero con 0

    printf("¡Bienvenido al juego de las 8 reinas!\n");
    printf("Ingresa la posición de las reinas (fila y columna) en el formato 'fila columna'.\n");

    for (int i = 0; i < N; i++) {
        int fila, columna;
        printf("Reina %d: ", i + 1);
        scanf("%d %d", &fila, &columna);

        if (fila < 0 || fila >= N || columna < 0 || columna >= N || tablero[fila][columna]) {
            printf("Error: Posición inválida o ya ocupada. Inténtalo de nuevo.\n");
            i--;
        } else {
            tablero[fila][columna] = 1;
        }
    }

    printf("Tu tablero:\n");
    imprimirTablero(tablero);

    if (esSolucionValida(tablero)) {
        printf("¡Eres un genio! Has resuelto el problema de las 8 reinas correctamente.\n");
    } else {
        printf("Lo siento, la solución no es válida. Inténtalo de nuevo.\n");
    }

    return 0;
}

