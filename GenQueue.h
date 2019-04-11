#ifndef GEN_QUEUE_H
#define GEN_QUEUE_H

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <typename T>
class GenQueue
{
    public:
        GenQueue();//default constructor
        ~GenQueue();//destructor

        void insert(T d);//insert an item at back
        T remove();//remove and item from front of queue
        T front();//returns element at the front

        bool isFull();//don't need becuase Linked-List does not fill
        bool isEmpty();//returns if the queue is empty
        int getSize();//returns number of elements in the queue

    private:
        DoublyLinkedList<T> *myQueue;
};

template <typename T>
inline GenQueue<T>::GenQueue()
{
    myQueue = new DoublyLinkedList<T>();
}

template <typename T>
inline GenQueue<T>::~GenQueue()
{
    delete myQueue;
}

template <typename T>
inline void GenQueue<T>::insert(T x)
{
    myQueue->insertBack(x);
}

template <typename T>
inline T GenQueue<T>::remove()
{
    return(myQueue->removeFront());
}

template <typename T>
inline T GenQueue<T>::front()
{
    return(myQueue->getFront());
}

template <typename T>
inline int GenQueue<T>::getSize()
{
    return(myQueue->getSize());
}

template <typename T>
inline bool GenQueue<T>::isEmpty()
{
    return(myQueue->isEmpty());
}


#endif
