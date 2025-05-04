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
    return true;
}

bool LinkedList::is_empty()
{
    if (this->_size == 0)
        return true;
    return false;
}

int LinkedList::size()
{
    return this->_size;
}

Node *LinkedList::find(int key)
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

Node *LinkedList::get(int pos)
{
    if (pos >= this->_size)
        return nullptr;
    Node *current = this->head;
    for (size_t i = 0; i < pos; i++)
    {
        current = head->next;
    }
    return current;
}

void LinkedList::print_last()
{
    Node *current = this->head;
    if (current != nullptr)
        return;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    printf("Last = |%d|\n", current->key);
}

bool LinkedList::equals(LinkedList *other)
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

bool LinkedList::pop_front()
{
    if (this->head == nullptr)
        return true;

    Node *head = this->head;
    Node *newHead = this->head->next;
    this->head = newHead;
    head->key = 0;
    head->next = nullptr;
    delete head;
    return true;
}

bool LinkedList::push_back(int key)
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
    for (size_t i = 0; i < n; i++)
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
}

bool LinkedList::pop_back()
{
    if (this->_size == 0)
    {
        return true;
    }
    Node *current = this->head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    delete current;
    this->_size = this->_size - 1;
    return true;
}

bool insert_sorted(int key) // Ex13
{
    
}

bool remove(int key) // Ex14
{
}

LinkedList *deep_copy() // Ex14
{
}

LinkedList *concat(LinkedList *list2) // Ex15
{
}

LinkedList *merge(LinkedList *list2) // Ex16
{
}

bool insert_after(int key, Node *pos)
{
    return true;
}

bool remove_after(Node *pos)
{
    return true;
}

bool insert(int pos)
{
    return true;
}

bool remove(int pos)
{
    return true;
}

bool remove(int key)
{
    return true;
}
