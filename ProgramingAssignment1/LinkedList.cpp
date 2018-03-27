#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
	head = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList){

    head = NULL;
	ListItem<T> *a = otherLinkedList.head;
	while(a->next != NULL){
		insertAtTail(a->value);
		a = a->next;
	}
	insertAtTail(a->value);

}

template <class T>
LinkedList<T>::~LinkedList(){
	while(head != NULL){
		deleteHead();
	}
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    ListItem<T> *temp=new ListItem<T>(item);
    if (head!=NULL)
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else
    {
        head=new ListItem<T>(item);
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    if (head!=NULL)
    {
        ListItem<T> *a=getTail();
        ListItem<T> *temp=new ListItem<T>(item);
        temp->value=item;
        temp->prev=a;
        temp->next=NULL;
        a->next=temp;
    }
    else
    {
        ListItem<T> *temp=new ListItem<T>(item);
        temp->value=item;
        temp->next=NULL;
        temp->prev=NULL;
        head=temp;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
if (head!=NULL)
    {
        ListItem<T> *a=searchFor(afterWhat);
        if (a!=NULL)
        {
            if (a->next!=NULL){
                ListItem<T> *temp=new ListItem<T>(toInsert);
                temp->next=a->next;
                temp->prev=a;
                a->next->prev=temp;
                a->next=temp;
            }
            else{
                ListItem<T> *temp=new ListItem<T>(toInsert);
                temp->next=NULL;
                temp->prev=a;
                a->next=temp;
            }
        }
    }
    else
        cout<<"Cant do head is null"<<endl;
}

template <class T>
void LinkedList<T>::insertSorted(T item)
{
    if (head!=NULL)
    {
        ListItem<T> *a=NULL;
        a=head;
        ListItem<T>  *c=NULL;
        T b=a->value;
        while (b<=item)
        {
            if (a->next!=NULL){
                c=a;
                a=a->next;
                b=a->value;
            }else
                break;
        }
        if (a==head && b>item){
            insertAtHead(item);
        }else if (b>item){
            insertAfter(item,c->value);
        }else{
            insertAtTail(item);
        }
    }else{
        insertAtHead(item);
    }
}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
    if (head!=NULL){
        return head;
    }else
        return NULL;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
    if (head==NULL)
        return NULL;
    else
    {
        ListItem<T> *a=head;
        while (a->next!=NULL)
        {
            a=a->next;
        }
        return a;
    }
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
    if (head!=NULL)
    {
        ListItem<T> *a=NULL;
        a=head;
        T b=a->value;
        while (b!=item){
            if (a->next!=NULL){
                a=a->next;
                b=a->value;
            }else
                break;
        }
        if (b==item){
            return a;
        }else{
            return NULL;
        }
    }
    else
        return NULL;
}


template <class T>
void LinkedList<T>::deleteElement(T item)
{
    if (head!=NULL){
        ListItem<T> *a=searchFor(item);
        if (a->next!=NULL&&a->prev!=NULL){
            a->prev->next=a->next;
            a->next->prev=a->prev;
            delete(a);
        }else if (a->prev==NULL)
            deleteHead();
        else if (a->next==NULL){
            delete(a);
            head=NULL;
        }
    }else
        cout<<"No data Yet"<<endl;
}

template <class T>
void LinkedList<T>::deleteHead(){

	if(getHead() == NULL)
		return;
	else if(getHead()->next == NULL){
		delete head;
		head = NULL;
	}
	else{
		ListItem<T> *temp = getHead()->next;
		temp->prev = NULL;
		delete head;
		head = temp;
	}
}

template <class T>
void LinkedList<T>::deleteTail()
{
    ListItem<T> *a=getTail();
    if (a->prev!=NULL)
        a->prev->next=NULL;
    else{
        delete head;
        head=NULL;
    }
}

template <class T>
int LinkedList<T>::length()
{
    if (head==NULL)
        return 0;
    else
    {
        int count=1;
        ListItem<T> *a=head;
        while (a->next!=NULL)
        {
            count++;
            a=a->next;
        }
        return count;
    }
}

template <class T>
void LinkedList<T>::reverse(){
	if(head == NULL) 
		return;
	ListItem<T> *iter = head;
	ListItem<T> *prev = NULL;
	ListItem<T> *next = NULL;

    while(iter != NULL){
        next = iter->next;
        iter->next = prev;
        prev = iter;
        iter = next;
    }
    head = prev;
}

template <class T>
void LinkedList<T>::parityArrangement()
{
    if (head!=NULL){
        ListItem<T> *b=new ListItem<T>(NULL);
        ListItem<T> *c=new ListItem<T>(NULL);
        ListItem<T> *iter=new ListItem<T>(NULL);
        ListItem<T> *a=head;
        iter->prev=NULL;
        b=iter;
        if (a->value%2==0){
            b->value=a->value;
            b->next=new ListItem<T>(NULL);
            b=b->next;
            c=b;
        }
        a=a->next;
        if (a!=NULL){
            while(a->next!=NULL){
                if (a->value%2==0){
                    b->value=a->value;
                    b->prev=new ListItem<T>(NULL);
                    b->prev=c;
                    b->next=new ListItem<T>(NULL);
                    c=b;
                    b=b->next;
                }
                a=a->next;
            }
            if(a->value%2==0){
                cout<<"Here is "<<a->value<<endl;
                b->value=a->value;
                b->prev=c;
                b->next=new ListItem<T>(NULL);
                c=b;
                b=b->next;
            }
        }else if (a->value%2==0)
            c->next=NULL;
        a=head;
        if (a->value%2==1){
            b->value=a->value;
            b->next=new ListItem<T>(NULL);
            b=b->next;
            c=b;
        }
        a=a->next;
        if (a!=NULL){
            while(a->next!=NULL){
                if (a->value%2==1){
                    b->value=a->value;
                    b->prev=new ListItem<T>(NULL);
                    b->prev=c;
                    b->next=new ListItem<T>(NULL);
                    c=b;
                    b=b->next;
                }
                a=a->next;
            }
            if (a->value%2==1){
                b->next=NULL;
                b->value=a->value;
                b->prev=c;
            }else
                c->next=NULL;
        }else if (a->value%2==0)
            c->next=NULL;
        head=iter;
    }
}

template <class T>
void LinkedList<T>::print()
{
    if (head!=NULL)
    {
        ListItem<T> *a=NULL;
        a=head;
        cout<<"Data Is "<<a->value<<endl;
        while (a->next!=NULL)
        {
            a=a->next;
            cout<<"Data Is ";
            cout<<a->value<<endl;

        }
    }
}

template <class T>
void LinkedList<T>::printr()
{
    ListItem<T> *tail=getTail();
    if (tail!=NULL)
    {
        ListItem<T> *a=tail;
        cout<<"Data Is "<<a->value<<endl;
        while (a->prev!=NULL)
        {
            cout<<"hello"<<endl;
            a=a->prev;
            cout<<"Data Is ";
            cout<<a->value<<endl;

        }
    }
}

#endif
