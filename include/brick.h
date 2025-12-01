#ifndef BRICK_H
#define BRICK_H

#define BRICK_ROWS 5
#define BRICK_COLS 10

typedef struct {
    int active;     // 1 si el ladrillo existe, 0 si está destruido
} Brick;

// Inicializa la matriz de ladrillos
void bricks_init();

// Devuelve un puntero a la matriz de ladrillos
Brick (*bricks_get())[BRICK_COLS];

// Marca un ladrillo como destruido
void brick_destroy(int row, int col);

#endif
