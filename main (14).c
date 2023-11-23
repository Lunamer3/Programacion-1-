/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enumeración para las opciones del juego.
typedef enum {
    PIEDRA,
    PAPEL,
    TIJERA,
    LAGARTO,
    SPOCK,
    MAX_OPCIONES
} Opcion;

// Función para obtener la elección del usuario.
Opcion obtenerEleccionUsuario() {
    int eleccion;
    printf("Elige una opcion (0: Piedra, 1: Papel, 2: Tijera, 3: Lagarto, 4: Spock): ");
    scanf("%d", &eleccion);
    return (Opcion)eleccion;
}

// Función para generar una elección aleatoria para el computador.
Opcion generarEleccionComputador() {
    return (Opcion)(rand() % MAX_OPCIONES);
}

// Función para determinar el ganador.
const char* determinarGanador(Opcion usuario, Opcion computador) {
    if (usuario == computador) {
        return "Empate!";
    }

    switch (usuario) {
        case PIEDRA:
            return (computador == TIJERA || computador == LAGARTO) ? "Ganaste!" : "Perdiste!";
        case PAPEL:
            return (computador == PIEDRA || computador == SPOCK) ? "Ganaste!" : "Perdiste!";
        case TIJERA:
            return (computador == PAPEL || computador == LAGARTO) ? "Ganaste!" : "Perdiste!";
        case LAGARTO:
            return (computador == SPOCK || computador == PAPEL) ? "Ganaste!" : "Perdiste!";
        case SPOCK:
            return (computador == TIJERA || computador == PIEDRA) ? "Ganaste!" : "Perdiste!";
        default:
            return "Opción inválida.";
    }
}

int main() {
    // Inicializar el generador de números aleatorios.
    srand(time(NULL));

    // Obtener elecciones de usuario y computador.
    Opcion eleccionUsuario = obtenerEleccionUsuario();
    Opcion eleccionComputador = generarEleccionComputador();

    // Mostrar elecciones.
    printf("Tu eleccion: %d\n", eleccionUsuario);
    printf("Eleccion del computador: %d\n", eleccionComputador);

    // Determinar y mostrar el ganador.
    printf("%s\n", determinarGanador(eleccionUsuario, eleccionComputador));

    return 0;
}


