#include <iostream>
#include "LinkedList.cpp"
#include <cstring>
#include<fstream>
#include <stdio.h>
#include <math.h>

class HashC
{
	protected:
		long tableSize;
		int collisions;
		int a;
		LinkedList<string>* hashTable;

	public:
		HashC(int _a);
		void Load(string file); // Load a file of Strings into your Hash table
		int hash(string); // Given a String, return its hash
		void insert(string word); // Takes a hash of 'word' and inserts it into hashTable accordingly
		ListItem<string>* lookup(string);
		int Collisions(); // Return number of collisions in hashTable
};

HashC::HashC(int _a){
    a=_a;
    tableSize=101;
    hashTable=new LinkedList<string>[tableSize];
    collisions=0;
}
void HashC::Load(string file){
    ifstream ifin;
	ifin.open(file.c_str());
	while (!ifin.eof()){
        string word;
        ifin>>word;
        insert(word);
	}
}
int HashC::hash(string word){
    int Hash1 = 0;
    for (int n=0;n<word.length();n++){
        Hash1 ^= (Hash1 << 5) + (Hash1 >> 2) + word[n];
    }
    return abs(Hash1)%tableSize;
}
void HashC::insert(string word){
    int hsh=hash(word);
    if (hashTable[hsh].getHead()==NULL)
        hashTable[hsh].insertAtHead(word);
    else{
        hashTable[hsh].insertAtHead(word);
        collisions++;
    }
}
ListItem<string>* HashC::lookup(string word){
    int hsh=hash(word);
    return hashTable[hsh].searchFor(word);
}
int HashC::Collisions(){
    return collisions;
}

int main(){
    string file;
	cout<<"Enter the file name:"<<endl;
	cin>>file;
	HashC obj(34);
	obj.Load (file);
    while (true){
        string data;
        cout << "Enter the data to search : ";
        cin>>data;
        if (obj.lookup(data))
            cout<<"Entry Found"<<endl;
        else
            cout<<"Entry not found"<<endl;
        int n;
        cout<< "Select 1 to continue : ";
        cin>>n;
        if (n!=1)
            break;
    }
}
