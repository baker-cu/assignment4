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
        void insertBack(T x);
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
};

template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
    size = 0;
    front = NULL;
    back = NULL;
}

template <typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
    delete front;
    delete back;
}

template <typename T>
inline void DoublyLinkedList<T>::insertFront(T x)
{
    ListNode *node = new ListNode(x);

    if (isEmpty)
    {
        back = node;
    }
    else
    {
        node->next = front;
        front->prev = node;
    }
    font = node;
    size++;
}

template <typename T>
inline void DoublyLinkedList<T>::insertBack(T x)
{

}

template <typename T>
inline T DoublyLinkedList<T>::removeFront()
{

}

template <typename T>
inline void DoublyLinkedList<T>::printList()
{
    //maybe used in template class idk
}

template <typename T>
inline T DoublyLinkedList<T>::find(T val)
{
    //maybe used in template class idk
}

template <typename T>
inline T DoublyLinkedList<T>::deletePos(int pos)
{

}

template <typename T>
inline bool DoublyLinkedList<T>::isEmpty()
{
    return(size == 0);
}

template <typename T>
inline unsigned int DoublyLinkedList<T>::getSize()
{
    return(size);
}
#endif DOUBLY_LINKED_LIST_H
