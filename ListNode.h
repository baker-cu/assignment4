#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

using namespace std;

template <typename T>
class ListNode
{
    public:
        ListNode();
        ListNode(int d);
        ~ListNode();

    private:
        T data;
        ListNode *next;
        ListNode *prev;
};

#endif LIST_NODE_H
