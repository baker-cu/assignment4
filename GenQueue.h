#ifndef GEN_QUEUE_H
#define GEN_QUEUE_H

#include <iostream>;

using namespace std;

template <typename T>
class GenQueue
{
    public:
        GenQueue();//default constructor
        GenQueue(int maxSize);//constructor
        ~GenQueue();//destructor

        void insert(T d);//insert an item at back
        T remove();//remove and item from front of queue
        T front();

        bool isFull();
        bool isEmpty();
        int getSize();

    private:
        int mSize;
        int head;//front of queue
        int tail;//front of queue
        int numElements;

        T *myQueue;
};

template <typename T>
inline GenQueue<T>::GenQueue()
{
    myQueue = new T[20];
    mSize = 20;
    numElements = 0;
    head = 0;
    tail = -1;
}

template <typename T>
inline GenQueue<T>::GenQueue(int maxSize)
{
    myQueue = new T[maxSize];
    mSize = maxSize;
    numElements = 0;
    head = 0;
    tail = -1;
}

template <typename T>
inline GenQueue<T>::~GenQueue()
{
    delete myQueue;
}

template <typename T>
inline void GenQueue<T>::insert(T x)
{
    //check if full...make bigger queue

    if(tail == mSize-1)
        tail = -1;

    myQueue[++tail] = x;
    ++numElements;
}

template <typename T>
inline T GenQueue::remove()
{
    //error checking

    if(head == msize)
        head = 0;

    T c = NULL;
    c = myQueue[head];

    ++head;
    numElements--;

    return c;
}


#endif GEN_QUEUE_H
