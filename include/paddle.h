#ifndef PADDLE_H
#define PADDLE_H

typedef struct {
    int x;      // posición del centro
    int width;
} Paddle;

void paddle_init();
void paddle_update(int direction);

Paddle* paddle_get();

#endif
