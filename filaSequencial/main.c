/// main.c
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void exibirFila(const Fila *fila)
{
    if (estaVazia(fila))
    {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    int i, indice = fila->frente;
    for (i = 0; i < fila->quantidade; i++)
    {
        printf("%d ", fila->elementos[indice]);
        indice = (indice + 1) % CAPACIDADE;
    }
    printf("\n");
}

int main()
{
    Fila fila;
    inicializar(&fila);

    adicionar(&fila, 10);
    adicionar(&fila, 20);
    adicionar(&fila, 30);
    adicionar(&fila, 40);
    adicionar(&fila, 50);
    adicionar(&fila, 60); // Deve falhar (fila cheia)

    exibirFila(&fila);

    int dado;
    if (espiar(&fila, &dado))
    {
        printf("Frente da fila: %d\n", dado);
    }

    while (retirar(&fila, &dado))
    {
        printf("Removido: %d\n", dado);
        exibirFila(&fila);
    }

    retirar(&fila, &dado); // Deve falhar (fila vazia)

    return 0;
}