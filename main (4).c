/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main() {
    char frase[1000];

    printf("Ingresa una frase: ");
    fgets(frase, sizeof(frase), stdin);

    int i = 0;
    while (frase[i]) {
        frase[i] = toupper(frase[i]);
        i++;
    }

    printf("La frase en mayúsculas es: %s", frase);

    return 0;
}

