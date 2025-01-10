#include "vectorlist.h"
#include <stdio.h>
#include <stdlib.h>

VectorList::VectorList()
{
    this->size = 0;
    this->capacity = 5;
    this->data = new int[this->capacity];
}

VectorList::VectorList(int size)
{
    this->size = 0;
    this->capacity = size * 2;
    this->data = new int[this->capacity];
}

int VectorList::push_back(int elem)
{
    if (this->size == this->capacity)
    {
        return 0;
    }
    this->data[this->size] = elem;
    this->size++;
    return 1;
}

void VectorList::print()
{
    printf("(%d/%d) ", this->size, this->capacity);
    for (int i = 0; i < this->size; i++)
    {
        printf("%d ", this->data[i]);
    }
    printf("\n");
}

int list_is_empty(VectorList *list)
{
    return (list->size == 0);
}

int list_is_full(VectorList *list)
{
    return (list->size == list->capacity);
}

int list_get_available(VectorList *list)
{
    return (list->capacity - list->size);
}

void list_clear(VectorList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        list->data[i] = 0;
    }

    list->size = 0;
}

void list_remove_last(VectorList *list, int n)
{
    if (n >= list->size)
    {
        list_clear(list);
        return;
    }

    if (list->size == 0)
        return;
    for (int i = (list->size) - 1; i > list->size - n; i--)
    {
        list->data[i] = 0;
    }
    list->size = (list->size) - n;
}

void list_print_reverse(VectorList *list)
{
    printf("(%d/%d) ", list->size, list->capacity);
    for (int i = (list->size) - 1; i >= 0; i--)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int list_find(VectorList *list, int elem)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

void list_add(VectorList *list, int n, int *vet)
{
    int ptr = 0;
    while (list->size < list->capacity && ptr < n)
    {
        list->push_back(vet[ptr]);
        ptr = ptr + 1;
    }
}

int list_is_sorted(VectorList *list)
{
    if (list->size == 0 || list->size == 1)
    {
        return 1;
    }
    int sentido = 0;
    for (int i = 0; i < (list->size); i++)
    {
        if (list->data[i] == list->data[i + 1])
        {
            continue;
        }

        if (list->data[i] < list->data[i + 1])
        {
            if (sentido == 1)
                continue;
            if (sentido == -1)
                return 0;
            if (sentido == 0)
            {
                sentido == 1;
                continue;
            }
        }

        if (list->data[i] > list->data[i + 1])
        {
            if (sentido == -1)
                continue;
            if (sentido == 1)
                return 0;
            if (sentido == 0)
            {
                sentido == 1;
                continue;
            }
        }
    }
    return 1;
}

void list_reverse(VectorList *list)
{
    if (list->size == 0 || list->size == 1)
        return;

    int temp = 0;
    for (int i = 0; i < list->size / 2; i++)
    {
        temp = list->data[i];
        list->data[i] = list->data[list->size - i - 1];
        list->data[list->size - i - 1] = temp;
    }
}

int list_equal(VectorList *list1, VectorList *list2)
{
    if (list1->size != list2->size)
    {
        return 0;
    }

    for (int i = 0; i < list1->size; i++)
    {
        if (list1->data[i] != list2->data[i])
            return 0;
    }
    return 1;
}

/*
Para implementar essa funcionalidade eu decidi usar a sobrecarga de construtor.
Criei um outro contrutor que recebe um inteiro por parâmetro e cria o vetor
Com o dobro daquele tamanho passado por parametro
Para fazr isso, fui no vectorlist.h e adicionei a assinatura do novo contrutor
struct VectorList {
    int size;
    int capacity;
    int* data;

    VectorList();
    VectorList(int size);    <---------------
    int push_back(int elem);
    void print();
};

e depois implementei o outro contrutor nesse mesmo arquivo
VectorList::VectorList(int size)
{
    this->size = 0;
    this->capacity = size * 2;   <-----------
    this->data = new int[this->capacity];
}
*/
VectorList *list_from_vector(int n, int *vet)
{
    VectorList *newList = new VectorList(n);
    for (int i = 0; i < n; i++)
    {
        newList->push_back(vet[i]);
    }
    return newList;
}

VectorList *list_copy(VectorList *list)
{
    VectorList *copyList = new VectorList();
    copyList->capacity = list->capacity;
    copyList->size = list->size;
    for (int i = 0; i < list->size; i++)
    {
        copyList->data[i] = list->data[i];
    }

    return copyList;
}