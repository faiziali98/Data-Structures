#ifndef __BST_H
#define __BST_H
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <queue>
#include "time.h"
#include <iostream>

using namespace std;

template <class T>
struct bst_node
{
        string value;
        T key;
        bst_node<T> *left;
        bst_node<T> *right;
        bst_node<T> *parent;

        bst_node(string val,T key1)
        {
                this->value=val;
                this->key=key1;
                this->parent=NULL;
                this->left=NULL;
                this->right=NULL;
        }
};

template <class T>
class bst
{
	bst_node<T> *root;

	public:
    bst_node<T> *searchFor(T key,bst_node<T> *b);
    bst_node<T> *searchForP(T key,bst_node<T> *b);
    bst_node<T>* searchItem(T key1,bst_node<T> *b);
    bst_node<T>* searchSuc(bst_node<T> *b);
    void print(bst_node<T> * p);
	bst();
	void insert(string val,T key1);
	bst_node<T>* search(T key1);
	void delete_node(T key1);
	int height(bst_node<T>* temp);
    void replace(T old_key,T new_key);
	bst_node<T>* getroot();
};
#endif
