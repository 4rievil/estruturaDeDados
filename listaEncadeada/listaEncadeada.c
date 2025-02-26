#include <stdio.h>
#include <stdlib.h>

// estrutura do nó da lista encadeada
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// estrutura da lista encadeada
typedef struct
{
    Node *head;
    int size;
} LinkedList;

// criação da lista vazia
LinkedList *createList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// verifica se a lista está vazia
int isEmpty(LinkedList *list) { return list->size == 0; }

// retorna o tamanho da lista
int getSize(LinkedList *list) { return list->size; }

// obtém o elemento na posição especificada (1-based)
int getElement(LinkedList *list, int pos)
{
    if (pos < 1 || pos > list->size)
        return -1; // validação de posição
    Node *current = list->head;
    while (--pos)
        current = current->next; // avança até a posição desejada
    return current->data;
}

// modifica o elemento na posição especificada (1-based)
void setElement(LinkedList *list, int pos, int value)
{
    if (pos < 1 || pos > list->size)
        return;
    Node *current = list->head;
    while (--pos)
        current = current->next;
    current->data = value;
}

// insere um novo elemento na posição especificada (1-based)
void insertElement(LinkedList *list, int pos, int value)
{
    if (pos < 1 || pos > list->size + 1)
        return; // validação de posição
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 1)
    { // inserção no início
        newNode->next = list->head;
        list->head = newNode;
    }
    else
    { // inserção em qualquer outra posição
        Node *current = list->head;
        while (--pos > 1)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// remove um elemento da posição especificada (1-based)
void removeElement(LinkedList *list, int pos)
{
    if (pos < 1 || pos > list->size)
        return; // validação de posição
    Node *temp, **current = &list->head;

    while (--pos)
        current = &(*current)->next; // encontra o ponteiro do nó anterior
    temp = *current;
    *current = temp->next; // remove o nó da lista

    free(temp);
    list->size--;
}

// imprime todos os elementos da lista
void printList(LinkedList *list)
{
    for (Node *current = list->head; current; current = current->next)
        printf("%d ", current->data);
    printf("\n");
}

// libera toda a memória da lista
void freeList(LinkedList *list)
{
    Node *current = list->head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

// testes para verificar o funcionamento da lista
int main()
{
    LinkedList *list = createList();

    insertElement(list, 1, 10);
    insertElement(list, 2, 20);
    insertElement(list, 3, 30);
    insertElement(list, 2, 15);

    printList(list);                                            // lista: 10 15 20 30
    printf("Elemento na posicao 2: %d\n", getElement(list, 2)); // deve imprimir 15

    setElement(list, 2, 25);
    printList(list); // lista: 10 25 20 30

    removeElement(list, 3);
    printList(list); // lista: 10 25 30

    printf("Tamanho: %d\n", getSize(list));                     // deve imprimir 3
    printf("Lista vazia? %s\n", isEmpty(list) ? "Sim" : "Nao"); // deve imprimir "Nao"

    freeList(list); // libera memória antes de sair
    return 0;
}
