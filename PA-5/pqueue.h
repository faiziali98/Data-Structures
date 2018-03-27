#ifndef PQUEUE__H
#define PQUEUE__H
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class pqueue
{
	protected:
		int size;
	public:
        int numE;
		vector<T> heap;
		pqueue();
		pqueue(vector<T> v);
        void minHeapify(int i,int m);
		T ExtractMin();
		void replace (int i,int j);
		void insert(T item);
		void UpdateDistance(T item, float distance);
};


#endif
