#ifndef __AVL_H
#define __AVL_H
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
//#include "time.h"
#include <queue>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


template <class T>
struct AvLNode
{
	string value;
	T key;
	int height;
	AvLNode *parent; // pointer to parent node
	AvLNode *left; // pointer to left child
	AvLNode *right; // pointer to right child

	/*You can add additional variables if necessary*/

	AvLNode(string Val, T k)
	{
	    height=0;
		this->value = Val;
		this->key = k;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};
template <class T>
class AvL
{
	AvLNode<T> *root;

public:
	// Constructor
	AvL();

	// Destructor
	~AvL();

	// Insertion Function
	void insert(string val, T k); // inserts the given key value pair into the tree

	void delete_node(T k); // deletes the node for the given key

	AvLNode<T> *search(T k); // takes key as an input and returns the node pointer if key exists and NULL pointer if key does not exists

	void replace(T oldk, T newk); // replaces old key with the new key, value remains same.

	int nodeHeight(AvLNode<T> *n); // returns height of the subtree from given node

	AvLNode<T> *getRoot(); // returns root of the AVL tree
    AvLNode<T> *searchFor(T key,AvLNode<T> *b);
    AvLNode<T> *searchForP(T key,AvLNode<T> *b);
    void print(AvLNode<T> * p);
    void updateHieght(AvLNode<T> *b);
    int diff(AvLNode<T> *temp);
    int Heights();
    AvLNode<T> *searchItem(T key,AvLNode<T> *b);
    AvLNode<T> *balance(AvLNode<T> *temp);
    AvLNode<T> *lRot(AvLNode<T> *parent);
    AvLNode<T> *rRot(AvLNode<T> *parent);
    AvLNode<T> *lrRot(AvLNode<T> *parent);
    AvLNode<T> *rlRot(AvLNode<T> *parent);
    int updateARot(AvLNode<T> *b);
    AvLNode<T> *FindOutB(AvLNode<T> *r);
    AvLNode<T>* searchSuc(AvLNode<T> *b);
	/*You can add additional functions if necessary*/
};

#endif
