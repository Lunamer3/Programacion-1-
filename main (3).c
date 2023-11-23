/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main() {
    float precioBruto, ivaPorcentaje, precioNeto;

    // Solicitar al usuario el precio de compra y el porcentaje de IVA
    printf("Ingrese el precio de compra: ");
    scanf("%f", &precioBruto);

    printf("Ingrese el porcentaje de IVA (por ejemplo, 16.0 para 16%%): ");
    scanf("%f", &ivaPorcentaje);

    // Calcular el precio neto
    precioNeto = precioBruto + (precioBruto * (ivaPorcentaje / 100));

    // Mostrar el precio neto
    printf("El precio neto es: %.2f\n", precioNeto);

    return 0;
}

