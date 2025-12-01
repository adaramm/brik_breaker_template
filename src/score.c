#include "score.h"
#include <stdio.h>
#include <string.h>

static Record records[10];
static int num_records = 0;
static int current_score = 0;

void score_reset() {
    current_score = 0;
}

void score_add(int amount) {
    current_score += amount;
}

int score_get() {
    return current_score;
}

void score_load(const char *filename) {
    FILE *f = fopen(filename, "r");
    num_records = 0;

    if (!f) return;

    while (fscanf(f, "%3s %d", records[num_records].name, &records[num_records].score) == 2) {
        num_records++;
        if (num_records >= 10) break;
    }

    fclose(f);
}

void score_save(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return;

    // Inserción simple del puntaje actual
    Record newRec;
    strcpy(newRec.name, "AAA");
    newRec.score = current_score;

    records[num_records++] = newRec;

    if (num_records > 10) num_records = 10;

    for (int i = 0; i < num_records; i++)
        fprintf(f, "%s %d\n", records[i].name, records[i].score);

    fclose(f);
}

void score_print() {
    printf("\n====== TOP 10 ======\n");
    for (int i = 0; i < num_records; i++)
        printf("%d) %s — %d\n", i + 1, records[i].name, records[i].score);
}
