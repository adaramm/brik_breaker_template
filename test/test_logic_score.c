#include <stdio.h>
#include "../include/score.h"

int main() {

    score_init("test_scores.txt");

    int old = score_get();

    score_add(10);

    if (score_get() != old + 10) {
        printf("❌ ERROR: score_add no suma correctamente.\n");
        return 1;
    }

    score_save("test_scores.txt");

    FILE *f = fopen("test_scores.txt", "r");
    if (!f) {
        printf("❌ ERROR: no se guarda el archivo de puntuaciones.\n");
        return 1;
    }
    fclose(f);

    printf("OK: lógica de puntajes.\n");
    return 0;
}
