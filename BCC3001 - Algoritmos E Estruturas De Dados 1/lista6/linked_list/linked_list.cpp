#include "linked_list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->_size = 0;
}

LinkedList::~LinkedList()
{
}

void LinkedList::print()
{
    Node *current = this->head;
    while (current)
    {
        cout << current->key << " ";
        current = current->next;
    }
    printf("\n");
}

bool LinkedList::push_front(int key)
{
    Node *newNode = new Node{key, nullptr};
    if (!newNode)
        return false;
    newNode->next = this->head;
    this->head = newNode;
    this->_size = this->_size + 1;
    return true;
}

bool LinkedList::is_empty() // Ex1
{
    if (this->_size == 0)
        return true;
    return false;
}

int LinkedList::size() // Ex2
{
    return this->_size;
}

Node *LinkedList::find(int key) // Ex3
{
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

Node *LinkedList::get(int pos) // Ex4
{
    if (pos >= this->_size || pos < 0)
        return nullptr;
    Node *current = this->head;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    return current;
}

void LinkedList::print_last() // Ex5
{
    Node *current = this->head;
    if (current == nullptr)
        return;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    printf("Last = |%d|\n", current->key);
}

bool LinkedList::equals(LinkedList *other) // Ex6
{
    if (this->head == nullptr || other == nullptr || other->head == nullptr)
        return false;
    if (this->_size != other->size())
        return false;

    Node *thisCurrent = this->head;
    Node *otherCurrent = other->head;

    while (thisCurrent != nullptr)
    {
        if (thisCurrent->key != otherCurrent->key)
            return false;
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }
    return true;
}

bool LinkedList::is_sorted() // Ex7
{
    if (this->_size == 0)
        return true;
    Node *current = this->head;
    int lastVal = INT32_MIN;
    while (current != nullptr)
    {
        if (current->key < lastVal)
        {
            return false;
        }
        lastVal = current->key;
        current = current->next;
    }
    return true;
}

bool LinkedList::pop_front() // Ex8
{
    if (this->head == nullptr)
        return true;

    if (this->_size == 1)
    {
        this->head->key = 0;
        delete this->head;
        this->head = nullptr;
        this->_size = 0;
        return true;
    }

    Node *head = this->head;
    Node *newHead = this->head->next;
    this->head = newHead;
    head->key = 0;
    head->next = nullptr;
    this->_size = this->_size - 1;
    delete head;
    return true;
}

bool LinkedList::push_back(int key) // Ex9
{
    Node *newNode = new Node();
    newNode->key = key;
    newNode->next = nullptr;
    if (this->head == nullptr)
    {
        this->head = newNode;
        return true;
    }
    Node *current = this->head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    this->_size = this->_size + 1;
    return true;
}

bool LinkedList::push_back(int n, int *vec) // Ex10
{
    Node *mainNode = new Node();
    mainNode->next = nullptr;
    Node *current = mainNode;
    if (n == 0)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        Node *tempPtr = new Node();
        tempPtr->key = vec[i];
        tempPtr->next = nullptr;
        current->next = tempPtr;
        current = current->next;
    }
    current = this->head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = mainNode->next;
    this->_size = this->_size + n;
    return true;
}

bool LinkedList::pop_back() // Ex11
{
    if (this->_size == 0)
    {
        return true;
    }
    if (this->_size == 1)
    {
        this->head->key = 0;
        this->head = nullptr;
        delete this->head;
        this->_size = 0;
        return true;
    }
    Node *current = this->head;
    while (current->next != nullptr && current->next->next != nullptr)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    this->_size = this->_size - 1;
    return true;
}

bool LinkedList::insert_sorted(int key) // Ex12
{
    if (this->head == nullptr)
    {
        return this->push_front(key);
    }

    Node *current = this->head;

    if (key < this->head->key)
        return this->push_front(key);

    while (current->next != nullptr)
    {
        if (current->next->key > key)
        {
            Node *newNode = new Node();
            newNode->key = key;
            newNode->next = current->next;
            current->next = newNode;
            this->_size = this->_size + 1;
            return true;
        }
        current = current->next;
    }
    return this->push_back(key);
}

bool LinkedList::remove(int key) // Ex13
{
    if (this->_size == 0)
    {
        return false;
    }
    Node *current = this->head;
    if (current->key == key)
    {
        this->head = current->next;
        this->_size = this->_size - 1;
        current->key = 0;
        current->next = nullptr;
        delete current;
        return true;
    }
    while (current->next != nullptr)
    {
        if (current->next->key == key)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            temp->key = 0;
            temp->next = nullptr;
            delete temp;
            this->_size = this->_size - 1;
            return true;
        }
        current = current->next;
    }
    return false;
}

LinkedList *LinkedList::deep_copy() // Ex14
{
    LinkedList *newLista = new LinkedList();
    if (this->head == nullptr)
    {
        newLista->head = nullptr;
        return newLista;
    }

    Node *current = this->head;
    Node *currentNew = new Node();
    currentNew->key = current->key;
    currentNew->next = nullptr;
    newLista->head = currentNew;

    while (current->next != nullptr)
    {
        current = current->next;
        Node *newNode = new Node();
        newNode->key = current->key;
        newNode->next = nullptr;
        currentNew->next = newNode;
        currentNew = newNode;
    }
    return newLista;
}

LinkedList *concat(LinkedList *list2) // Ex15
{
    return nullptr;
}

LinkedList *merge(LinkedList *list2) // Ex16
{
    return nullptr;
}