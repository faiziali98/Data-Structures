#ifndef __BST_CPP
#define __BST_CPP
#include <iostream>
#include "bst.h"
using namespace std;
template <class T>
bst<T>::bst()
{
    root=NULL;
}

template <class T>
bst_node<T> *bst<T>::searchFor(T key,bst_node<T> *b){
    if (b==NULL){
        return b;
    }else{
        if (b->key>key){
            return searchFor(key,b->left);
        }else if(b->key<key){
            return searchFor(key,b->right);
        }
    }
}

template <class T>
bst_node<T> *bst<T>::searchForP(T key,bst_node<T> *b){
    if ((b->key>key && b->left==NULL)||(b->key<key && b->right==NULL)){
        return b;
    }else{
        if (b->key>key){
            return searchForP(key,b->left);
        }else if(b->key<key){
            return searchForP(key,b->right);
        }
    }
}

template <class T>
void bst<T>::insert(string val,T key1)
{
    if (root==NULL){
        root=new bst_node<T>(val,key1);
    }else{
        bst_node<T> *temp=searchFor(key1,root);
        bst_node<T> *temp1=searchForP(key1,root);
        temp=new bst_node<T>(val,key1);
        temp->parent=temp1;
        if (temp1->key>key1){
            temp1->left=temp;
        }else if(temp1->key<key1){
            temp1->right=temp;
        }
    }
}

template <class T>
bst_node<T>* bst<T>::searchItem(T key,bst_node<T> *b){
    if (b!=NULL){
        if (b->key==key){
            return b;
        }else{
            if (b->key>key){
                return searchItem(key,b->left);
            }else if(b->key<key){
                return searchItem(key,b->right);
            }
        }
    }else
        return NULL;
}

template <class T>
bst_node<T>* bst<T>::search(T key1){
    return searchItem(key1,root);
}

template <class T>
bst_node<T>* bst<T>::searchSuc(bst_node<T> *b){
    if (b->left==NULL){
        return b;
    }else{
        return searchSuc(b->left);
    }
}

template <class T>
void bst<T>::delete_node(T key1){
    bst_node<T> *temp=searchItem(key1,root);
    bst_node<T> *temp1=temp->parent;
    if (temp!=root){
        if (temp->left==NULL && temp->right==NULL){
            if (key1>temp1->key){
                temp1->right=NULL;
                delete temp;
            }else if (key1<temp1->key){
                temp1->left=NULL;
                delete temp;
            }
        }else if ((temp->left!=NULL && temp->right==NULL) || (temp->left==NULL && temp->right!=NULL)){
            if (temp->left!=NULL && temp->right==NULL){
                if (key1>temp1->key){
                    temp->left->parent=temp1;
                    temp1->right=temp->left;
                    delete temp;
                }else if (key1<temp1->key){
                    temp->left->parent=temp1;
                    temp1->left=temp->left;
                    delete temp;
                }
            }else if (temp->left==NULL && temp->right!=NULL){
                if (key1>temp1->key){
                    temp->right->parent=temp1;
                    temp1->right=temp->right;
                    delete temp;
                }else if (key1<temp1->key){
                    temp->right->parent=temp1;
                    temp1->left=temp->right;
                    delete temp;
                }
            }
        }else{
            bst_node<T> *temp2=searchSuc(temp->right);
            if (temp2->parent==temp){
                temp2->parent=temp1;
                temp2->left=temp->left;
                if(temp==temp1->left)
                    temp1->left=temp2;
                else if(temp==temp1->right)
                    temp1->right=temp2;
            }else if (temp2->right==NULL){
                temp2->parent->left=NULL;
                temp2->parent=temp1;
                temp2->left=temp->left;
                temp2->right=temp->right;
                if(temp==temp1->left)
                    temp1->left=temp2;
                else if(temp==temp1->right)
                    temp1->right=temp2;
            }else if (temp2->right!=NULL){
                temp2->parent->left=temp2->right;
                temp2->parent=temp1;
                temp2->left=temp->left;
                temp2->right=temp->right;
                if(temp==temp1->left)
                    temp1->left=temp2;
                else if(temp==temp1->right)
                    temp1->right=temp2;
            }
        }
    }else{
        if (temp->left==NULL && temp->right==NULL){
            delete temp;
        }else if ((temp->left!=NULL && temp->right==NULL) || (temp->left==NULL && temp->right!=NULL)){
            if (temp->left!=NULL && temp->right==NULL){
                temp->left->parent=NULL;
                root=temp->left;
            }else if (temp->left==NULL && temp->right!=NULL){
                temp->right->parent=NULL;
                root=temp->right;
            }
        }else{
            bst_node<T> *temp2=searchSuc(temp->right);
            if (temp2->parent==temp){
                temp2->parent=NULL;
                temp2->left=temp->left;
                root=temp2;
            }else if (temp2->right==NULL){
                temp2->parent->left=NULL;
                temp2->parent=NULL;
                temp2->left=temp->left;
                temp2->right=temp->right;
                root=temp2;
            }else if (temp2->right!=NULL){
                temp2->parent->left=temp2->right;
                temp2->parent=NULL;
                temp2->left=temp->left;
                temp2->right=temp->right;
                root=temp2;
            }
        }
    }
}

template <class T>
int bst<T>::height( bst_node<T> *temp){
    int hit=0;
    if (temp!=NULL && (temp->left!=NULL||temp->right!=NULL)){
        return 1+max(height(temp->left),height(temp->right));
    }else
        return hit;
}

template<class T>
void bst<T>::replace(T old_key,T new_key){
    insert(searchItem(old_key,root)->value,new_key);
    delete_node(old_key);

	print(getroot());
}

template <class T>
bst_node<T>* bst<T>::getroot()
{
    return root;
}

template <class T>
void bst<T>::print(bst_node<T> * p){

    if (!p) return;
  		queue<bst_node<T> *> nodesQueue;
  	 int nodesInCurrentLevel = 1;
  	 int nodesInNextLevel = 0;
  		nodesQueue.push(root);
  	while (!nodesQueue.empty()) {
    	bst_node<T> *currNode = nodesQueue.front();
    	nodesQueue.pop();
    	nodesInCurrentLevel--;

    	if (currNode) {
    		cout << currNode->key << " ";
      		nodesQueue.push(currNode->left);
      		nodesQueue.push(currNode->right);
      		nodesInNextLevel += 2;
    	}

    	if (nodesInCurrentLevel == 0) {
      		cout << endl;
      		nodesInCurrentLevel = nodesInNextLevel;
      		nodesInNextLevel = 0;
    	}
    }
}

#endif
