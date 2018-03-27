#include "Chaining.h"

using namespace std;

HashC::HashC(int _a){
    a=_a;
    tableSize=100067;
    hashTable=new LinkedList<string>[tableSize];
    collisions=0;
}
void HashC::Load(char* file){
    ifstream ifin;
	ifin.open(file);
	while (!ifin.eof()){
        string word;
        ifin>>word;
        insert(word);
	}
}
int HashC::hash(string word){
    int j=word.length();
    int hsh=0;
    for (int n=0;n<word.length();n++){
        hsh=hsh+pow(a,j-1)*word[n];
        j--;
    }
    return abs(hsh)%tableSize;
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
