#include "game.h"
#include "ball.h"
#include "paddle.h"
#include "bricks.h"
#include "score.h"
#include <stdio.h>

// Flag interno
static int finished = 0;

// TODO: El estudiante debe implementar la lógica del juego
void game_init() {
    finished = 0;
    paddle_init();
    
}

void game_update() {
    // TODO: actualizar barra, pelota, colisiones, puntaje
}

void game_render() {
    // TODO: limpiar pantalla y dibujar todo
}

int game_is_over() {
    return finished;
}
