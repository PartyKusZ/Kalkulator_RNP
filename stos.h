#include <stdio.h>
#include <stdlib.h>
#ifndef STOS_H
#define STOS_H


typedef struct stos {
    int dana;
    struct stos *nast;
} t_stos;

void inicjuj(t_stos **stos);
int empty(t_stos **stos);
void print(t_stos **stos);
void push(t_stos **stos, int *dana);
void pop(t_stos **stos, int *dana);
#endif