#pragma once

// Definicao do TAD Lista Encadeada

class Node {
public:
    int key;
    Node* next;
};


class LinkedList {
private:
    Node* head;
    int _size;

public:
    LinkedList();
    ~LinkedList();
    
    void print();
    
    bool is_empty(); // Ex1
    int size(); // Ex2
    Node* find(int key); // Ex3
    Node* get(int pos); // Ex4
    void print_last(); // Ex5
    bool equals(LinkedList* other); // Ex6
    bool is_sorted(); // Ex7
    bool pop_front(); // Ex8
    bool push_back(int key); // Ex9
    bool push_back(int n, int* vec); // Ex10
    bool pop_back(); // Ex11
    bool insert_sorted(int key); // Ex13
    bool remove(int key); // Ex14
    LinkedList* deep_copy(); // Ex14
    LinkedList* concat(LinkedList* list2); // Ex15
    LinkedList* merge(LinkedList* list2); // Ex16

    bool push_front(int key);
};