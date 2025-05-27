#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "vectorlist.h"

int main()
{
    VectorList *list = new VectorList();

    int arr[] = {3, 4};
    int n = 2;
    VectorList *list2 = new VectorList();
    VectorList *list3 = new VectorList();
    list2->push_back(1);
    list2->push_back(2);
    list2->push_back(3);

    list3->push_back(5);
    list3->push_back(4);
    list3->push_back(3);

    VectorList *listfromArr = nullptr;
    VectorList *listCopied = nullptr;

    std::cout << "Lista iniciada vazia.\n";
    list->print();
    std::cout << "Está vazia? " << list_is_empty(list) << "\n";
    std::cout << "Adicionando o 1\n";
    list->push_back(1);
    list->print();
    std::cout << "Está vazia? " << list_is_empty(list) << "\n";
    std::cout << "Número de espaços disponíveis: " << list_get_available(list) << "\n";
    std::cout << "Adicionando o 2\n";
    list->push_back(2);
    list->print();
    std::cout << "Adicionando o 3 e o 4 em lote\n";
    list_add(list, n, arr);
    list->print();
    std::cout << "Está cheia? " << list_is_full(list) << "\n";
    std::cout << "Adicionando o 5\n";
    list->push_back(5);
    list->print();
    std::cout << "Imprimindo em reverso...\n";
    list_print_reverse(list);
    std::cout << "Procurando o 2" << list_find(list, 2) << "\n";
    std::cout << "Está ordenada? " << list_is_sorted(list) << "\n";
    std::cout << "Está cheia? " << list_is_full(list) << "\n";
    list->print();
    std::cout << "Invertendo..." << "\n";
    list_reverse(list);
    list->print();
    std::cout << "Removendo os dois ultimos\n";
    list_remove_last(list, 2);
    list->print();
    std::cout << "Lista 2";
    list2->print();
    std::cout << "Lista 3";
    list3->print();
    std::cout << "A lista é igual a lista 2? " << list_equal(list, list2) << "\n";
    std::cout << "A lista é igual a lista 3? " << list_equal(list, list3) << "\n";
    std::cout << "Criando uma lista a partir de um vetor...\n";
    listfromArr = list_from_vector(n, arr);
    listfromArr->print();
    std::cout << "Criando um cópia da lista...\n";
    listCopied = list_copy(list);
    listCopied->print();
    std::cout << "Limpando a lista\n";
    list_clear(list);
    list->print();

    std::cout << "Concatenando listas\n";
    list->push_back(7);
    list->push_back(8);
    list->push_back(9);
    list->print();
    list2->print();
    int concatenados = list_concat(list, list2);

    list->print();
    std::cout << "Concatenados: " << concatenados << "\n";
    return 0;
}