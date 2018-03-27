#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{

}

template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue){

	ListItem<T> *iter = otherQueue.list.head;
	while(iter != NULL){
		enqueue(iter->value);
		iter = iter->next;
	}
}

template <class T>
Queue<T>::~Queue()
{
    //list.~LinkedList();
}

template <class T>
void Queue<T>::enqueue(T item)
{
    list.insertAtTail(item);
}

template <class T>
T Queue<T>::front()
{
    return (list.getHead()->value);
}

template <class T>
T Queue<T>::dequeue()
{
    T b=list.getHead()->value;
    list.deleteHead();
    return (b);
}

template <class T>
int Queue<T>::length()
{
    return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
    if (list.length()==0)
        return 0;
    else
        return 1;
}


#endif
