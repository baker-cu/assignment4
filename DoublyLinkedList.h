#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>


using namespace std;

template <typename T>
class ListNode
{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();


        T data;
        ListNode *next;
        ListNode *prev;
};

template <typename T>
inline ListNode<T>::ListNode()
{
    data = NULL;
    next = NULL;
    prev = NULL;
}

template <typename T>
inline ListNode<T>::ListNode(T d)
{
    data = d;
    next = NULL;
    prev = NULL;
}

template <typename T>
inline ListNode<T>::~ListNode()
{
    next = NULL;
    prev = NULL;
}

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
        int find(int val);//maybe

        T deletePos(int pos);
        bool isEmpty();

        unsigned int getSize();
        T getFront();
        T getPos(int pos);

    private:
        ListNode<T> *front;
        ListNode<T> *back;
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
    ListNode<T> *node = new ListNode<T>(x);

    if (isEmpty())
    {
        back = node;
    }
    else
    {
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}

template <typename T>
inline void DoublyLinkedList<T>::insertBack(T x)
{
    ListNode<T> *node = new ListNode<T>(x);

    if(isEmpty())
        front = node;

    else
    {
        node->prev = back;
        back->next = node;
    }
    back = node;
    size++;
}

template <typename T>
inline T DoublyLinkedList<T>::removeFront()
{
    ListNode<T> *node = front;
    if(isEmpty())
        throw string("List is empty.");
    if(front->next == NULL)
    {
        back = NULL;
    }
    else
    {
        front->next->prev = NULL;
    }
    front = front->next;
    T temp = node->data;
    node->next = NULL;

    delete node;
    size--;

    return temp;
}

/*template <typename T>
inline void DoublyLinkedList<T>::printList()
{
    //maybe used in template class idk
}

template <typename T>
inline T DoublyLinkedList<T>::find(T val)
{
    //maybe used in template class idk
}*/

template <typename T>
inline T DoublyLinkedList<T>::deletePos(int pos)
{
    int idx = 0;

    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while(idx != pos)
    {
        prev = curr;
        curr = curr->next;
        ++idx;
    }

    //when we find the next position
    prev->next = curr->next;
    curr->next = NULL;

    T temp = curr->data;
    delete curr;
    size--;

    return temp;
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

template <typename T>
inline T DoublyLinkedList<T>::getFront()
{
    return(front->data);
}

template <typename T>
inline T DoublyLinkedList<T>::getPos(int pos)
{
    int idx = 0;

    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while(idx != pos)
    {
        prev = curr;
        curr = curr->next;
        ++idx;
    }
    T temp = curr->data;
    return temp;
}



#endif
