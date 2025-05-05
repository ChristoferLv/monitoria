#include <stdio.h>
#include <iostream>
#include "linked_list.h"

using namespace std;
int main()
{
    LinkedList *list1 = new LinkedList();
    LinkedList *list2 = new LinkedList();
    LinkedList *list3 = new LinkedList();
    Node *temp = nullptr;

    cout << "Vazia? " << list1->is_empty() << "\n";
    list1->push_front(3);
    list1->push_front(8);
    list1->push_front(2);
    list1->push_front(5);
    list1->push_front(7);
    list1->print();
    cout << "Lista Inicializada\n";
    cout << "Vazia? " << list1->is_empty() << "\n";

    cout << "Tamanho: " << list1->size() << "\n";

    temp = list1->find(2);
    cout << temp << ": " << temp->key << "\n";

    temp = list1->get(1);
    cout << temp << ": " << temp->key << "\n";

    list1->print_last();

    list2->push_front(3);
    list2->push_front(8);
    list2->push_front(2);
    list2->push_front(5);
    list2->push_front(7);

    cout << "Igual? " << list1->equals(list2) << "\n";
    cout << "Igual? " << list1->equals(list3) << "\n";

    list3->push_front(7);
    list3->push_front(5);
    list3->push_front(2);

    cout << "Ordenada? " << list1->is_sorted() << "\n";
    cout << "Ordenada? " << list3->is_sorted() << "\n";

    list1->print();
    list1->pop_front();
    list1->print();

    cout << "Insere 0 no fim\n";
    list1->push_back(0);
    list1->print();

    int vec[4] = {6, 9, 4, 2};
    list1->push_back(4, vec);
    list1->print();

    cout << "Remove o ultimo\n";
    list1->pop_back();
    list1->print();

    list3->print();
    list3->insert_sorted(1);
    list3->print();
    list3->insert_sorted(4);
    list3->print();
    list3->insert_sorted(6);
    list3->print();
    list3->insert_sorted(9);
    list3->print();

    list1->print();
    list1->remove(3);
    list1->print();
    list1->remove(5);
    list1->print();
    list1->remove(4);
    list1->print();

    LinkedList *novaLista;
    novaLista = list1->deep_copy();
    cout << "Lista original: ";
    list1->print();
    cout << "Lista copiada: ";
    novaLista->print();

    LinkedList *novaListaConcat;
    novaListaConcat = list1->concat(list2);
    cout << "Lista 1: ";
    list1->print();
    cout << "Lista 2: ";
    list2->print();
    cout << "Lista concatenada: ";
    novaListaConcat->print();

    LinkedList* list4 = new LinkedList();
    list4->push_back(1);
    list4->push_back(3);
    list4->push_back(4);
    list4->push_back(8);
    LinkedList *novaListaMerge;
    novaListaMerge = list3->merge(list4);
    cout << "Lista 1: ";
    list3->print();
    cout << "Lista 2: ";
    list4->print();
    cout << "Lista merged: ";
    novaListaMerge->print();
    delete list1;
}