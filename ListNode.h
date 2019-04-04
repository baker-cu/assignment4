#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

using namespace std;

template <typename T>
class ListNode
{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();

    private:
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

#endif
