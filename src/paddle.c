#include "paddle.h"

static Paddle paddle;

void paddle_init() {
    // TODO: colocar el paddle centrado
}

void paddle_update(int direction) {
    // TODO: mover el paddle según la dirección (-1 izquierda, 1 derecha)
}

Paddle* paddle_get() {
    return &paddle;
}
