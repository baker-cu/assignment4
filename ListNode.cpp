#ifndef LIST_NODE_C
#define LIST_NODE_C

#include <iostream>

using namespace std;

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
inline ListNode::~ListNode()
{
    next = NULL;
    prev = NULL;
}

#endif LIST_NODE_C
