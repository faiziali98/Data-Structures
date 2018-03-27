#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "ArrayList.h"
#include<iostream>
using namespace std;

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& otherArrayList){
    size=otherArrayList.size;
    capacity=otherArrayList.capacity;
    T *temp=otherArrayList.array;
    array=new T[capacity];
    for (int n=0; n<size;n++){
        array[n]=temp[n];
    }
}

template <class T>
ArrayList<T>::~ArrayList(){
	delete array;
}

template <class T>
void ArrayList<T>::insertAtHead(T item){
    if (size==0){
        array[0]=item;
        size++;
    }else{
        if (size>=capacity)
            resize();
        T *temp=new T[capacity];
        for (int n=0;n<size;n++){
            temp[n+1]=array[n];
        }
        temp[0]=item;
        size++;
        array=temp;
    }
}

template <class T>
void ArrayList<T>::insertAtTail(T item){
    if (size==0){
        array[0]=item;
        size++;
    }else{
        if (size>=capacity)
            resize();
        array[size]=item;
        size++;
    }
}

template <class T>
void ArrayList<T>::insertAfter(T toInsert, T afterWhat){
    if (size==0){
        array[0]=toInsert;
        size++;
    }else{
        int a=searchFor(afterWhat);
        if (a!=-1){
            if (a!=size-1){
                if (size>=capacity)
                    resize();
                T *temp=new T[capacity];
                for (int n=a+1;n<size;n++)
                    temp[n+1]=array[n];
                temp[a+1]=toInsert;
                size++;
                for (int n=a+1;n<size;n++)
                    array[n]=temp[n];
            }else{
                insertAtTail(toInsert);
            }
        }
    }
}

template <class T>
void ArrayList<T>::insertSorted(T item){
    if (size==0){
        array[0]=item;
        size++;
    }else{
        int n;
        for (n=0;n<size;n++){
            if (item<=array[n])
                break;
        }
        if (n==0)
            insertAtHead(item);
        else if (n==size-1)
            insertAtTail(item);
        else
            insertAfter(item,array[n-1]);
    }
}

template <class T>
T ArrayList<T>::getAt(int i){
    return array[i];
}

template <class T>
int ArrayList<T>::searchFor(T item){
    for (int n=0;n<size;n++){
        if (array[n]==item){
            return n;
        }
    }
    return -1;
}

template <class T>
void ArrayList<T>::deleteElement(T item){
    if (size!=0){
        int a=searchFor(item);
        if (a!=-1){
            deleteAt(a);
        }
    }
}

template <class T>
void ArrayList<T>::deleteAt(int i){
    if (size!=0){
        if (i==0){
            deleteHead();
        }else if (i==size-1){
            deleteTail();
        }else {
             T *temp=new T[capacity];
             int g=0;int g1=0;
             while (g<size-1){
                if (g1!=i){
                    temp[g]=array[g1];
                    g++;
                }
                g1++;
             }
             array=temp;
             size--;
        }
    }
}

template <class T>
void ArrayList<T>::deleteHead(){
    if (size!=0){
        T *temp=new T[capacity];
        for (int n=1;n<size;n++)
            temp[n-1]=array[n];
        array=temp;
        size--;
    }
}

template <class T>
void ArrayList<T>::deleteTail(){
    if (size!=0){
        T *temp=new T[capacity];
        for (int n=0;n<size-1;n++)
            temp[n]=array[n];
        array=temp;
        size--;
    }
}

template <class T>
void ArrayList<T>::resize(){
    capacity=capacity*2;
    T *temp=array;
    array=new T[capacity];
    for (int n=0;n<size;n++){
        array[n]=temp[n];
    }
}

template <class T>
int ArrayList<T>::length(){
    return size;
}

template <class T>
void ArrayList<T>::reverse(){
    T *temp=new T[capacity];
    int g=0;int g1=size-1;
    while(g1>=0){
        temp[g]=array[g1];
        g++;g1--;
    }
    array=temp;
}

template <class T>
void ArrayList<T>::print()
{
    for(int n=0;n<size;n++){
        cout<<array[n]<<endl;
    }
}

#endif
