#include "pqueue.h"

template<class T>
void pqueue<T>::replace (int i,int j){
    T temp=heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
    i = j;
}

template<class T>
pqueue<T>::pqueue(){
    size=0;
    numE=size-1;
}

template<class T>
pqueue<T>::pqueue(vector<T> v){
    size=v.size();
    numE=size-1;
    for (int n=0;n<size;n++){
        heap.push_back(v[n]);
    }
}

template<class T>
T pqueue<T>::ExtractMin(){
    int i=(numE/2);
    while(i >= 0) {
        minHeapify(i, numE);
        i--;
    }
    minHeapify(0,numE);
    T n=heap[0];
    //replace(heap,0,numE);
    numE--;
    size--;
    heap.erase(heap.begin());
    return n;
}

template<class T>
void pqueue<T>::minHeapify(int i,int m){
    int big, c1, c2;
    while(i < m) {
        big = i;
        c1 = (2*i) + 1;
        c2 = c1 + 1;
        if( m >=c1 && heap[c1]<heap[big])
            big = c1;
        if( m>=c2 && heap[c2]<heap[big])
            big = c2;
        if(big != i){
            replace(i,big);
            i = big;
        }else break;
    }
}

template<class T>
void pqueue<T>::insert(T item){
    heap.push_back(item);
    size++;
    numE++;
}

/*int main(){
    vector<int> m;
    m.push_back(10);
    m.push_back(10);
    m.push_back(10);
    m.push_back(10);
    m.push_back(0);
    pqueue<int> p(m);
    cout<<p.ExtractMin()<<endl;
}*/
