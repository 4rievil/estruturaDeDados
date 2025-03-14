/// fila.c
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(Fila *fila)
{
    fila->frente = 0;
    fila->tras = -1;
    fila->quantidade = 0;
}

bool estaVazia(const Fila *fila)
{
    return fila->quantidade == 0;
}

bool estaCheia(const Fila *fila)
{
    return fila->quantidade == CAPACIDADE;
}

bool adicionar(Fila *fila, int dado)
{
    if (estaCheia(fila))
    {
        fprintf(stderr, "Erro: Fila cheia!\n");
        return false;
    }
    fila->tras = (fila->tras + 1) % CAPACIDADE;
    fila->elementos[fila->tras] = dado;
    fila->quantidade++;
    return true;
}

bool retirar(Fila *fila, int *dado)
{
    if (estaVazia(fila))
    {
        fprintf(stderr, "Erro: Fila vazia!\n");
        return false;
    }
    *dado = fila->elementos[fila->frente];
    fila->frente = (fila->frente + 1) % CAPACIDADE;
    fila->quantidade--;
    return true;
}

bool espiar(const Fila *fila, int *dado)
{
    if (estaVazia(fila))
    {
        fprintf(stderr, "Erro: Fila vazia!\n");
        return false;
    }
    *dado = fila->elementos[fila->frente];
    return true;
}