#include <stdio.h>
#include "game.h"
#include "score.h"

int main() {
    // Inicializa el sistema de puntajes y crea el archivo si no existe.
    // TODO: Se debe completar esta función en score.c
    score_init("scores.txt");

    // Inicializa el juego (carga ladrillos, posiciones iniciales, etc.)
    game_init();

    // Bucle principal del juego.
    // TODO: Debe llamar a: input_update(), game_update(), render_frame().
    // Se implementa en game.c
    while (!game_is_over()) {
        game_loop_step();
    }

    // Guarda la puntuación del jugador al final del juego
    // se implementa score_save()
    score_save("scores.txt");

    return 0;
}
