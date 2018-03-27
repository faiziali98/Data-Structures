#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include <time.h>
#include <cstdlib>
//=====================================================================================
vector<long> InsertionSort(vector<long> nums){
    int temp, x, siz=nums.size();
    int arr[siz];
    for (int n=0;n<siz;n++)
        arr[n]=nums[n];
    for (int i=0;i<siz;i++){
        temp=arr[i];
        x=i;
        while (x>0 && arr[x-1]>temp){
            arr[x]=arr[x-1];
            x--;
        }

        arr[x]=temp;
    }
    for (int n=0;n<siz;n++)
        nums[n]=arr[n];
    return nums;
}

//=====================================================================================

ListItem<long> *Merge(ListItem<long>* list1, ListItem<long>* list2){
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->value <= list2->value) {
        list1->next = Merge(list1->next, list2);
        return list1;
    } else {
        list2->next = Merge(list2->next, list1);
        return list2;
    }
}

List<long> MergeSortL(List<long> l){
    if (l.length() <= 1)
       return l;
    else{
        int mid=l.length()/2;
        ListItem <long>*ls=l.getHead();
        List<long> left;
        List<long> right;

        while (true){
            if (ls!=NULL){
                left.insertAtTail(ls->value);
                ls=ls->next;
            }else break;
            if (ls!=NULL){
                right.insertAtTail(ls->value);
                ls=ls->next;
            }else break;
        }

        left=MergeSortL(left);
        right=MergeSortL(right);

        if ((left.getTail()->value)<=(right.getHead()->value)){
            mid=right.length();
            for (int k=0;k<mid;k++){
                left.insertAtTail(right.getHead()->value);
                right.deleteHead();
            }
            return left;
        }

        List<long> result;
        result.head = Merge(left.getHead(), right.getHead());

        return result;
    }
}

vector<long> MergeSort(vector<long> nums){
    List<long> l;
    int siz=nums.size();

    for (int n=0;n<siz;n++)
        l.insertAtTail(nums[n]);

    l=MergeSortL(l);

    for (int n=0;n<siz;n++){
        nums[n]=l.getHead()->value;
        l.deleteHead();
    }

    return nums;
}



//=====================================================================================

void swap (long *arr,int l,int h){
    long temp=arr[l];
    arr[l]=arr[h];
    arr[h]=temp;
}

int MedianOfThree(long *arr, int left, int right){
    int mid = (left + right)/2;
    if (arr[right] < arr[left])
        swap(arr, left, right);
    if (arr[mid] < arr[left])
        swap(arr, mid, left);
    if (arr[right] < arr[mid])
        swap(arr, right, mid);
    return mid;
}

int position(long *arr, int l, int h,int piv){
    int index;
    if (piv==1)
        index=l;
    else if (piv==2)
        index=h;
    else if (piv==3)
        index=MedianOfThree(arr,l,h);
    int value = arr[index];
    swap(arr, index, h);
    int finalPos = l;
    for (int i=l;i<=h-1;i++){
        if (arr[i] < value){
            swap(arr, i, finalPos);
            finalPos ++;
        }
    }
    swap(arr, finalPos, h);
    return finalPos;
}

long *quicksort(long *arr, int l, int h,int piv){
    if (l < h){
        int p = position(arr,l,h,piv);
        arr=quicksort(arr,l,p-1,piv);
        arr=quicksort(arr,p+1,h,piv);
    }
    return arr;
}

vector<long> QuickSortArray(vector<long> nums){
    int siz=nums.size();
    long *arr=new long[siz];

    for (int n=0;n<siz;n++)
        arr[n]=nums[n];

    cout<<"What type of pivot you want?"<<endl;
    int piv; cin>>piv;
    arr=quicksort(arr,0,nums.size()-1,1);

    for (int n=0;n<siz;n++)
        nums[n]=arr[n];

    return nums;
}

void swap(long &x,long &y){
	long t = x;
	x = y;
	y = t;
}

void QuickSort(List<long>& linkedList ,ListItem<long> *start ,ListItem<long> *end);
ListItem<long> *partitionLinkedList(List<long>& linkedList,ListItem<long> *start ,ListItem<long> *end);

vector<long> QuickSortList(vector<long> nums){

	List<long> linkedList;

	for(int i=0;i<nums.size();++i)
		linkedList.insertAtTail(nums[i]);

	QuickSort(linkedList,linkedList.getHead(),linkedList.getTail());

	int index = 0;
	for(ListItem<long> *iterator = linkedList.getHead();iterator;iterator=iterator->next)
		nums[index++] = iterator->value;

	return nums;
}

void QuickSort(List<long>& linkedList ,ListItem<long> *start ,ListItem<long> *end){

	ListItem<long> *index;

	if(start!=NULL && end != NULL && start != end && start != end->next){
		index = partitionLinkedList(linkedList,start,end);
		QuickSort(linkedList,start,index->prev);
    	QuickSort(linkedList,index->next,end);
	}
}

ListItem<long> *partitionLinkedList(List<long>& linkedList,ListItem<long> *start ,ListItem<long> *end){
    int pivot = end->value;
    ListItem<long> *new_start = start;
    ListItem<long> *i = start;

    while( i != end){
    	if(i->value < pivot){
    		swap(i->value,new_start->value);
    		new_start = new_start->next;
    	}
    	i=i->next;
    }
    swap(new_start->value,end->value);
    return new_start;
}
//=====================================================================================
long *maxHeapify(long *arr,int i, int m) {
    int big, c1, c2;
    while(i < m) {
        big = i;
        c1 = (2*i) + 1;
        c2 = c1 + 1;
        // if left child is bigger
        if( c1<m && arr[c1]>arr[big] )
            big = c1;
        // if right child is bigger
        if( c2<m && arr[c2]>arr[big] )
            big = c2;
        // if there is an abnormality
        if(big != i){
            long temp=arr[i];
            arr[i]=arr[big];
            arr[big]=temp;
            i = big;
        }else break;
    }
    return arr;
}

long *heap_sort(long *arr,int siz) {
    int i=(siz/2)-1;
    while(i >= 0) {
        // rest of half are leafs we don't have to check for them
        arr=maxHeapify(arr, i, siz);
        i--;
    }
    int itr=siz-1;
    while (itr> 0) {
        // finding max and putting it at end
        long temp=arr[0];
        arr[0]=arr[itr];
        arr[itr]=temp;
        // max heapifying the rest on the array so that we have maximum value at node again
        arr=maxHeapify(arr, 0, itr);
        itr--;
    }
    return arr;
}
vector<long> HeapSort(vector<long> nums){
    int siz=nums.size();
    long *arr=new long[siz];
    for (int n=0;n<siz;n++)
        arr[n]=nums[n];
    arr=heap_sort(arr,siz);
    for (int n=0;n<siz;n++)
        nums[n]=arr[n];
    return nums;
}

//=====================================================================================
vector<long> BucketSort(vector<long> nums, int max){
    List<long>* hashTable=new List<long>[max+1];
    for (int k=0;k<nums.size();k++){
            hashTable[nums[k]].insertAtHead(nums[k]);
    }
    int itr=0;
    for (int k=0;k<max+1;k++){
         if (hashTable[k].getHead()!=NULL){
            while (hashTable[k].length()){
                nums[itr]=hashTable[k].getHead()->value;
                hashTable[k].deleteHead();
                itr++;
            }
         }
    }

    return nums;
}

#endif
