#ifndef VECTORLIST_H
#define VECTORLIST_H

// Definicao do TAD Lista Sequencial

struct VectorList {
    int size;
    int capacity;
    int* data;

    VectorList();
    VectorList(int size);
    int push_back(int elem);
    void print();
};

int list_is_empty(VectorList* list); //1
int list_is_full(VectorList* list); //2
int list_get_available(VectorList* list); //3
void list_clear(VectorList* list); //4
void list_remove_last(VectorList* list, int n); //5
void list_print_reverse(VectorList* list); //6
int list_find(VectorList* list, int elem); //7
void list_add(VectorList* list, int n, int* vet); //8
int list_is_sorted(VectorList* list); //9
void list_reverse(VectorList* list); //10
int list_equal(VectorList* list1, VectorList* list2); //11
VectorList* list_from_vector(int n, int* vet); //12
VectorList* list_copy(VectorList* list); //13
int list_concat(VectorList* list1, ListSet* list2); //14

#endif