#include <stdio.h>
#include "../include/ball.h"

int main() {
    Ball *b;

    ball_init();
    b = ball_get();

    int old_x = b->x;
    int old_y = b->y;

    ball_update();

    if (b->x == old_x && b->y == old_y) {
        printf("❌ ERROR: La pelota no se mueve.\n");
        return 1;
    }

    // Simular choque con pared izquierda
    b->x = 0;
    b->dx = -1;
    ball_update();

    if (b->dx != 1) {
        printf("❌ ERROR: La pelota no rebota correctamente en la pared izquierda.\n");
        return 1;
    }

    // Simular choque con pared derecha
    b->x = 79;
    b->dx = 1;
    ball_update();

    if (b->dx != -1) {
        printf("❌ ERROR: La pelota no rebota en la pared derecha.\n");
        return 1;
    }

    printf("OK: lógica de pelota.\n");
    return 0;
}
