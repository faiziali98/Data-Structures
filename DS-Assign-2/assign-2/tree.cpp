#ifndef __TREE_CPP
#define __LIST_CPP
#include "tree.h"
#include <fstream>

Tree::Tree()
{
    head=NULL;
}
vector<string> v;
string *splitStr(string line,char dil){
    v.clear();
    string *arr;
    int count=0;
    for (int n=0;n<line.length();n++){
        if (line[n]==dil)
            count++;
    }
    arr=new string[count+1];
    int itrb=0; int itrf=1; int size=1;
    for (int n=0;n<=count;n++){
        while (line[itrf]!=dil && line[itrf]!=NULL){
            itrf++;
            size++;
        }
        arr[n]=line.substr(itrb,size);
        v.push_back(arr[n]);
        itrf++;
        itrb=itrf;
        size=0;
    }
    return arr;
}

int counter;
string ff;
Tree::Tree(string file)
{
    head=NULL;
    ff=file;
    ifstream f(file.c_str());
	string line;
    string *arr;
    counter=1;
    while(!(f.eof())){
        getline(f,line);
        arr=splitStr(line,'/');
        int count=0;
        for (int n=0;n<line.length();n++){
        if (line[n]=='/')
            count++;
        }
        for (int n=0;n<=count;n++){
            string t=arr[n];
            if (t[0]!=NULL){
                insert(arr[n]);
                counter++;
            }
        }
       counter=1;
	}
}

Tree::~Tree()
{
}

TreeItem * searchFor(string item,TreeItem *t){
    if (t->value==item){
        return t;
    }else{
        vector<TreeItem*> vc;
        TreeItem *c = t->FChild;
        while(c){
            vc.push_back(c);
            c = c->NextS;
        }
        TreeItem *ret=NULL;

        for (int n=0;n<vc.size() && ret==NULL;n++){
            ret=searchFor(item,vc[n]);
        }
        return ret;
    }
}

void Tree::insert(string item)
{
    if (head==NULL){
        head=new TreeItem(item);
    }else if (head->FChild==NULL){
        TreeItem *t1=new TreeItem(item);
        t1->Parent=head;
        head->FChild=t1;
    }else if (counter==3){
        TreeItem *temp=head;
        int k=1;
        for (int n=1;n<counter-1;n++){
            temp=temp->FChild;
        }
        if (temp->FChild!=NULL){
                temp=temp->FChild;
        }else{
            TreeItem *t1=new TreeItem(item);
            t1->Parent=temp;
            temp->FChild=t1;
            k=0;
        }
        if (k==1){
            TreeItem *temp2=temp;
            if (temp2->value!=item){
                while(temp2->NextS!=NULL){
                    if (temp2->value==item){
                        break;
                    }else
                        temp2=temp2->NextS;
                }
                if (temp2->NextS==NULL && temp2->value!=item){
                    TreeItem *t1=new TreeItem(item);
                    t1->Parent=temp2->Parent;
                    temp2->NextS=t1;
                }
            }
        }
    }else{
        TreeItem *temp=searchFor(item,head);
        if (temp==NULL){
            int n;
            for (n=0;n<v.size();n++){
                if (v[n]==item)
                    break;
            }
            TreeItem *temp1=searchFor(v[n-1],head);
            TreeItem *t1=new TreeItem(item);
            t1->Parent=temp1;
            if (temp1->FChild==NULL){
                temp1->FChild=t1;
            }else{
                TreeItem *temp2=temp1->FChild;
                while(temp2->NextS!=NULL){
                    temp2=temp2->NextS;
                }
                temp2->NextS=t1;
            }
        }
    }
}

vector<string> Tree::Locate(string qry)
{
    vector<string> v;
    TreeItem *temp=searchFor(qry,head);
    if (temp!=NULL){
        while(temp->Parent!=NULL){
            v.push_back(temp->value);
            temp=temp->Parent;
        }
        v.push_back(temp->value);
        return v;
    }
    return v;
}

string Tree::LComAc(string a, string b)
{
    TreeItem *temp=searchFor(a,head);
    TreeItem *temp1=searchFor(b,head);

    vector<TreeItem*> vc;
    vector<TreeItem*> vc1;

    while(temp->Parent!=NULL){
        vc.push_back(temp);
        temp=temp->Parent;
    }
    vc.push_back(temp);
    while(temp1->Parent!=NULL){
        vc1.push_back(temp1);
        temp1=temp1->Parent;
    }
    vc1.push_back(temp1);

    for (int n=0;n<vc.size();n++){
       for (int n1=0;n1<vc1.size();n1++){
            if (vc[n]==vc1[n1])
                return vc[n]->value;
       }
    }
}

TreeItem* Tree::getHead()
{
	return head;
}

bool contains (string one, char dil){
	int g=0;
	for (int n=0;n<one.length();n++){
			if (one[n]==dil)
                g++;
	}
	if (g==1)
        return true;
}

int Tree::countFiles()
{
    ifstream f(ff.c_str());
    string line;
    string *arr;
    vector<string> v;
    while(!(f.eof())){
        getline(f,line);
        arr=splitStr(line,'/');
        int count=0;
        for (int n=0;n<line.length();n++){
            if (line[n]=='/')
                count++;
        }
        for (int n=0;n<=count;n++){
            string t=arr[n];
            v.push_back(t);
        }
	}
	int count=0;
	for (int n=0;n<v.size();n++){
        if (contains(v[n],'.')){
            count++;
        }
	}
	return count;
}


#endif
