#ifndef __AVL_CPP
#define __AVL_CPP
#include "avl.h"

template <class T>
int AvL<T>::diff(AvLNode<T> *temp){
    if (temp->left!=NULL && temp->right!=NULL){
        int l_height = temp->left->height;
        int r_height = temp->right->height;
        int b_factor= l_height - r_height;
        return b_factor;
    }else if (temp->left==NULL && temp->right!=NULL){
        int l_height = -1;
        int r_height = temp->right->height;
        int b_factor= l_height - r_height;
        return b_factor;
    }else if (temp->left!=NULL && temp->right==NULL){
        int l_height = temp->left->height;
        int r_height = -1;
        int b_factor= l_height - r_height;
        return b_factor;
    }else
        return 0;
}

template <class T>
AvLNode<T> *AvL<T>::searchFor(T key,AvLNode<T> *b){
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
AvLNode<T> *AvL<T>::searchForP(T key,AvLNode<T> *b){
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
void AvL<T>::updateHieght(AvLNode<T> *b){
    if (b!=NULL){
        b->height=nodeHeight(b);
        while(b->parent!=NULL){
            b=b->parent;
            b->height=nodeHeight(b);
        }
    }
}

template <class T>
AvL<T>::AvL()
{
    root=NULL;
}

template <class T>
AvL<T>::~AvL()
{
}

template <class T>
AvLNode<T>* AvL<T>::searchItem(T key,AvLNode<T> *b){
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
AvLNode<T>* AvL<T>::search(T k){
    return searchItem(k,root);
}

template <class T>
void AvL<T>::replace(T ok, T nk){
    insert(searchItem(ok,root)->value,nk);
    delete_node(ok);
}

template <class T>
AvLNode<T>* AvL<T>::searchSuc(AvLNode<T> *b){
    if (b->left==NULL){
        return b;
    }else{
        return searchSuc(b->left);
    }
}

template <class T>
void AvL<T>::delete_node(T k){
    AvLNode<T> *temp=searchItem(k,root);
    AvLNode<T> *temp1=temp->parent;
    AvLNode<T> *t;
    if (temp!=root){
        if (temp->left==NULL && temp->right==NULL){
            if (k>temp1->key){
                temp1->right=NULL;
                t=temp1;
                delete temp;
            }else if (k<temp1->key){
                temp1->left=NULL;
                t=temp1;
                delete temp;
            }
        }else if ((temp->left!=NULL && temp->right==NULL) || (temp->left==NULL && temp->right!=NULL)){
            if (temp->left!=NULL && temp->right==NULL){
                if (k>temp1->key){
                    temp->left->parent=temp1;
                    temp1->right=temp->left;
                    t=temp->left;
                    delete temp;
                }else if (k<temp1->key){
                    temp->left->parent=temp1;
                    temp1->left=temp->left;
                    t=temp->left;
                    delete temp;
                }
            }else if (temp->left==NULL && temp->right!=NULL){
                if (k>temp1->key){
                    temp->right->parent=temp1;
                    temp1->right=temp->right;
                    t=temp->right;
                    delete temp;
                }else if (k<temp1->key){
                    temp->right->parent=temp1;
                    temp1->left=temp->right;
                    t=temp->right;
                    delete temp;
                }
            }
        }else{
            AvLNode<T> *temp2=searchSuc(temp->right);
            if (temp2->parent==temp){
                temp2->parent=temp1;
                temp2->left=temp->left;
                if(temp==temp1->left){
                    temp1->left=temp2;
                    t=temp1->left;
                }else if(temp==temp1->right){
                    temp1->right=temp2;
                    t=temp1->right;
                }
            }else if (temp2->right==NULL){
                temp2->parent->left=NULL;
                temp2->parent=temp1;
                temp2->left=temp->left;
                temp2->right=temp->right;
                if(temp==temp1->left){
                    temp1->left=temp2;
                    t=temp1->left;
                }else if(temp==temp1->right){
                    temp1->right=temp2;
                    t=temp1->right;
                }
            }else if (temp2->right!=NULL){
                temp2->parent->left=temp2->right;
                temp2->parent=temp1;
                temp2->left=temp->left;
                temp2->right=temp->right;
                if(temp==temp1->left){
                    temp1->left=temp2;
                    t=temp1->left;
                }else if(temp==temp1->right){
                    temp1->right=temp2;
                    t=temp1->right;
                }
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
            AvLNode<T> *temp2=searchSuc(temp->right);
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
        t=root;
    }
    updateARot(root);
    if (t!=NULL){
        AvLNode<T> *t1=FindOutB(t);
        if (t1!=NULL && t1==root){
            root=balance(t1);
        }else if (t1!=NULL){
            AvLNode<T> *p=t1->parent;
            if (p->left==t1){
                AvLNode<T> *r=balance(t1);
                r->parent=p;
                p->left=r;
            }else if (p->right==t1){
                AvLNode<T> *r=balance(t1);
                r->parent=p;
                p->right=r;
            }
        }
        int heigh=updateARot(root);
    }
}

template <class T>
AvLNode<T> *AvL<T>::lRot(AvLNode<T> *parent){
    AvLNode<T> *temp = parent->right;
    temp->parent=parent->parent;
    parent->right = temp->left;
    temp->left = parent;
    parent->parent=temp;
    return temp;
}

template <class T>
AvLNode<T> *AvL<T>::rRot(AvLNode<T> *parent){
    AvLNode<T> *temp = parent->left;
    temp->parent=parent->parent;
    parent->left = temp->right;
    temp->right = parent;
    parent->parent=temp;
    return temp;
}

template <class T>
AvLNode<T> *AvL<T>::rlRot(AvLNode<T> *parent){
    AvLNode<T> *temp = parent->left;
    parent->left = lRot(temp);
    return rRot(parent);
}

template <class T>
AvLNode<T> *AvL<T>::lrRot(AvLNode<T> *parent){
    AvLNode<T> *temp = parent->right;
    parent->right = rRot(temp);
    return lRot(parent);
}

template <class T>
AvLNode<T> *AvL<T>::balance(AvLNode<T> *temp){
    if (temp!=NULL){
        int differ = diff (temp);
        if (differ > 1){
            if (diff (temp->left) > 0){
                temp = rRot(temp);
            }else{
                temp = rlRot(temp);
            }
        }else if (differ < -1){
            if (diff (temp->right) > 0){
                temp = lrRot(temp);
            }else{
                temp = lRot(temp);
            }
        }
        return temp;
    }else
        return temp;
}
template <class T>
int AvL<T>::updateARot(AvLNode<T> *b){
    if (b!=NULL){
        if (b->left==NULL && b->right==NULL){
            b->height=0;
            return b->height;
        }else if (b->left!=NULL && b->right==NULL){
            b->height=1+updateARot(b->left);
            return b->height;
        }else if (b->left==NULL && b->right!=NULL){
            b->height=1+updateARot(b->right);
            return b->height;
        }else if (b->left!=NULL && b->right!=NULL){
            b->height=1+max(updateARot(b->right),updateARot(b->left));
            return b->height;
        }
    }
}

template <class T>
AvLNode<T> * AvL<T>::FindOutB(AvLNode<T> *r){
    AvLNode<T> *temp=r;
    while (temp!=NULL){
        if (diff (temp)<-1 || diff (temp)>1)
            return temp;
        temp=temp->parent;
    }
    return NULL;
}

template <class T>
void AvL<T>::insert(string val, T k){
    if (root == NULL){
        root = new AvLNode<T>(val,k);
    }else{
        AvLNode<T> *temp=searchFor(k,root);
        AvLNode<T> *temp1=searchForP(k,root);
        temp=new AvLNode<T>(val,k);
        temp->parent=temp1;
        if (temp1->key>k){
            temp1->left=temp;
        }else if(temp1->key<k){
            temp1->right=temp;
        }
        updateHieght(temp1);
        AvLNode<T> *temp2=FindOutB(temp);
        if (temp2!=NULL && temp2==root){
            root=balance(temp2);
        }else if (temp2!=NULL){
            AvLNode<T> *p=temp2->parent;
            if (p->left==temp2){
                AvLNode<T> *r=balance(temp2);
                r->parent=p;
                p->left=r;
            }else if (p->right==temp2){
                AvLNode<T> *r=balance(temp2);
                r->parent=p;
                p->right=r;
            }
        }
        int heigh=updateARot(root);
    }
}

template<class T>
int AvL<T>::Heights(){
    cout<<diff(root)<<endl;
}

template<class T>
int AvL<T>::nodeHeight( AvLNode<T> *n){
    int hit=0;
    if (n!=NULL && (n->left!=NULL||n->right!=NULL)){
        return 1+max(nodeHeight(n->left),nodeHeight(n->right));
    }else
        return hit;
}

template<class T>
AvLNode<T>* AvL<T>::getRoot(){
	return root;
}

template <class T>
void AvL<T>::print(AvLNode<T> * p){
    if (!p) return;
  		queue<AvLNode<T> *> nodesQueue;
  	 int nodesInCurrentLevel = 1;
  	 int nodesInNextLevel = 0;
  		nodesQueue.push(root);
  	while (!nodesQueue.empty()) {
    	AvLNode<T> *currNode = nodesQueue.front();
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
