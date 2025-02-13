#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

// 1. CRIAR LISTA VAZIA
void criarLista(Lista *l) {
    l->tamanho = 0;
}

// 2. VERIFICAR SE A LISTA ESTÁ VAZIA
int estaVazia(Lista *l) {
    return l->tamanho == 0;
}

// 3. VERIFICAR SE A LISTA ESTÁ CHEIA
int estaCheia(Lista *l) {
    return l->tamanho == MAX;
}

// 4. OBTER O TAMANHO DA LISTA
int obterTamanho(Lista *l) {
    return l->tamanho;
}

// 5. OBTER VALOR DO ELEMENTO
int obterElemento(Lista *l, int pos) {
    if (pos < 1 || pos > l->tamanho) {
        printf("Posição inválida!\n");
        return -1;
    }
    return l->dados[pos - 1];
}

void modificarElemento(Lista *l, int pos, int valor) {
    if (pos < 1 || pos > l->tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    l->dados[pos - 1] = valor;
}

// 6. INSERIR ELEMENTO EM UMA POSIÇÃO
void inserirElemento(Lista *l, int pos, int valor) {
    if (estaCheia(l)) {
        printf("Lista cheia!\n");
        return;
    }
    if (pos < 1 || pos > l->tamanho + 1) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = l->tamanho; i >= pos; i--) {
        l->dados[i] = l->dados[i - 1];
    }
    l->dados[pos - 1] = valor;
    l->tamanho++;
}

// 7. REMOVER ELEMENTO
void removerElemento(Lista *l, int pos) {
    if (estaVazia(l)) {
        printf("Lista vazia!\n");
        return;
    }
    if (pos < 1 || pos > l->tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = pos - 1; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->tamanho--;
}

// IMPRIMIR LISTA
void imprimirLista(Lista *l) {
    printf("Lista: ");
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

// MAIN
int main() {
    Lista lista;
    criarLista(&lista);
    
    inserirElemento(&lista, 1, 10);
    inserirElemento(&lista, 2, 20);
    inserirElemento(&lista, 3, 30);
    imprimirLista(&lista);
    
    removerElemento(&lista, 2);
    imprimirLista(&lista);
    
    modificarElemento(&lista, 2, 50);
    imprimirLista(&lista);
    
    return 0;
}