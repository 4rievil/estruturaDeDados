/// fila.h
#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

#define CAPACIDADE 5

typedef struct Fila
{
    int elementos[CAPACIDADE];
    int frente, tras, quantidade;
} Fila;

void inicializar(Fila *fila);
bool estaVazia(const Fila *fila);
bool estaCheia(const Fila *fila);
bool adicionar(Fila *fila, int dado);
bool retirar(Fila *fila, int *dado);
bool espiar(const Fila *fila, int *dado);

#endif // FILA_H