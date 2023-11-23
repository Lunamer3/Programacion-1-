/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

int main() {
    int i, j;
    char tablero[8][8];

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i == 0 || i == 7) && (j == 0 || j == 7)) {
                tablero[i][j] = 'T';
            } else if ((i == 0 || i == 7) && (j == 1 || j == 6)) {
                tablero[i][j] = 'C';
            } else if ((i == 0 || i == 7) && (j == 2 || j == 5)) {
                tablero[i][j] = 'A';
            } else if ((i == 0 || i == 7) && (j == 3)) {
                tablero[i][j] = 'R';
            } else if ((i == 0 || i == 7) && (j == 4)) {
                tablero[i][j] = 'Q';
            } else if (i == 1 || i == 6) {
                tablero[i][j] = 'P';
            } else {
                tablero[i][j] = ' ';
            }
        }
    }

    // Imprimir el tablero
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
    #include <stdlib.h>
#include <stdio.h>

int main() {
    int i, j;
    char tablero[8][8];

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i == 0 || i == 7) && (j == 0 || j == 7)) {
                tablero[i][j] = 'T';
            } else if ((i == 0 || i == 7) && (j == 1 || j == 6)) {
                tablero[i][j] = 'C';
            } else if ((i == 0 || i == 7) && (j == 2 || j == 5)) {
                tablero[i][j] = 'A';
            } else if ((i == 0 || i == 7) && (j == 3)) {
                tablero[i][j] = 'R';
            } else if ((i == 0 || i == 7) && (j == 4)) {
                tablero[i][j] = 'Q';
            } else if (i == 1 || i == 6) {
                tablero[i][j] = 'P';
            } else {
                tablero[i][j] = ' ';
            }
        }
    }

    // Imprimir el tablero (lado derecho)
    for (i = 0; i < 8; i++) {
        for (j = 7; j >= 0; j--) { // Recorremos en orden inverso para el lado derecho
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }

    return 0;
}


    return 0;
}

