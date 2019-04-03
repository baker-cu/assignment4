#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList
{
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insertFront(T x);
        T removeFront();

        void printList();//maybe
        T find(T val);//maybe

        T deletePos(int pos);
        bool isEmpty();
        unsigned int getSize();

    private:
        ListNode *front;
        ListNode *back;
        unsigned int size; // can't be negative
}

#endif DOUBLY_LINKED_LIST_H
