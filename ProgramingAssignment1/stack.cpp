#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
}

template <class T>
Stack<T>::Stack(const Stack<T>& otherStack){

	ListItem<T> *iter = otherStack.list.head;
	while(iter->next != NULL){
		iter = iter->next;
	}
	while(iter != NULL){
		push(iter->value);
		iter = iter->prev;
	}
}


template <class T>
Stack<T>::~Stack()
{
   // list.~LinkedList();
}

template <class T>
void Stack<T>::push(T item)
{
    list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
    return (list.getHead()->value);
}

template <class T>
T Stack<T>::pop()
{
    T b=list.getHead()->value;
    list.deleteHead();
    return (b);
}

template <class T>
int Stack<T>::length()
{
    return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (list.length()==0)
        return true;
    else
        return false;
}

#endif
