#ifndef BRICK_H
#define BRICK_H

#include "library_compat.h"

/* ============================
   Constantes de tablero
   ============================ */
#define WIDTH 48
#define HEIGHT 24
#define PADDLE_W 7
#define BRICK_ROWS 5
#define BRICK_COLS 12
#define BRICK_W 3

/* ============================
   Tipos de datos
   ============================ */

/*
 * Estructura: Ball
 * Descripción: Representa la pelota: posición (x,y) y velocidad (vx,vy).
 */
typedef struct {
    double x;
    double y;
    double vx;
    double vy;
} Ball;

/*
 * Estructura: Paddle
 * Descripción: Representa la paleta del jugador.
 */
typedef struct {
    int x;      /* posición izquierda */
    int y;      /* fila (constante cerca del fondo) */
    int width;  /* ancho (PADDLE_W) */
} Paddle;

/* Matriz de ladrillos: 1 = vivo, 0 = destruido */
extern int bricks[BRICK_ROWS][BRICK_COLS];

/* ============================
   Prototipos de funciones (con comentarios explicativos)
   ============================ */

/*
 * mostrarMenu
 * -------------- 
 * Muestra el menú principal del juego con opciones:
 * 1) Jugar
 * 2) Instrucciones
 * 3) Salir
 * Debe leer la opción del usuario y actuar en consecuencia.
 */
void mostrarMenu(void);

/*
 * iniciarJuego
 * --------------
 * Inicializa el estado del juego:
 * - Inicializa matriz de ladrillos (todos activos).
 * - Posiciona la paleta y la pelota.
 * - Inicializa variables de score/vidas.
 * No realiza el loop principal: sólo prepara el estado.
 */
void iniciarJuego(void);

/*
 * runGameLoop
 * --------------
 * Ejecuta el bucle principal del juego:
 * - Lee entrada del jugador (mover paleta).
 * - Actualiza la posición de la pelota.
 * - Detecta y maneja colisiones (paredes, paleta, ladrillos).
 * - Renderiza la pantalla (usando printf y ANSI).
 * - Controla framerate.
 * Debe finalizar cuando se gana o se pierde y mostrar el resultado.
 */
void runGameLoop(void);

/*
 * dibujarPantalla
 * --------------
 * Dibuja el tablero actual en consola:
 * - Bordes, ladrillos, paleta y pelota.
 * - HUD (score, vidas).
 * Debe usar únicamente printf (y escapes ANSI para color).
 */
void dibujarPantalla(void);

/*
 * actualizarPelota
 * --------------
 * Calcula la siguiente posición de la pelota según su velocidad.
 * Aplica rebotes contra paredes y techo (invertir vx o vy).
 * No maneja colisión con paleta ni ladrillos (esas se delegan).
 */
void actualizarPelota(void);

/*
 * checkColisiones
 * --------------
 * Detecta y maneja colisiones relevantes:
 * - Colisión con paleta: invertir componente vertical y modificar vx según zona de impacto.
 * - Colisión con ladrillos: marcar ladrillo como destruido, invertir vy y aumentar score.
 * - Colisión con borde inferior: restar vida y reiniciar pelota (o terminar).
 */
void checkColisiones(void);

/*
 * moverPaleta
 * --------------
 * Mueve la paleta a la izquierda o derecha.
 * - dir: -1 = izquierda, +1 = derecha, 0 = sin movimiento
 * Debe limitar la paleta para que no salga del área de juego.
 */
void moverPaleta(int dir);

/*
 * reiniciarPelota
 * --------------
 * Coloca la pelota en la posición inicial sobre la paleta y establece velocidad inicial.
 */
void reiniciarPelota(void);

#endif // BRICK_H
