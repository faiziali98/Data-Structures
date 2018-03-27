#ifndef __QUEUE_H
#define __QUEUE_H
#include "LinkedList.cpp"

/* This is the generic Queue class */
template <class T>
class Queue
{

  public:
     LinkedList<T> list;
    // Constructor
    Queue();

    // Copy Constructor
    Queue(const Queue<T>& otherQueue);

    // Destructor
    ~Queue();

    // Required Methods
    void enqueue(T item);
    T front();
    T dequeue();
    int length();
    bool isEmpty();
};

#endif
