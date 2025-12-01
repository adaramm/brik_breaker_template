#ifndef SCORE_H
#define SCORE_H

void score_init(const char *filename);
void score_add(int points);
void score_save(const char *filename);

int score_get();

#endif
