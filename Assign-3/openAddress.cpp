#include "openAddress.h"


OpenAddress::OpenAddress(int A){
    a=A;
    collisions=0;
    tableSize=100067;
    items=0;
    hashTable=new string[tableSize];
}
void OpenAddress::Load(char* file){
    ifstream ifin;
	ifin.open(file);
	while (!ifin.eof()){
        string word;
        ifin>>word;
        insertItem(word);
	}
}
int OpenAddress::hash(string word){
    int j=word.length()-1;
    int hsh=0;
    for (int i=0; i<word.size(); i++) {
		hsh += (int) word[i] * pow(a,j); //Polynomial Hash Code
		j--;
	}
    return (abs(hsh)%tableSize);
}
long OpenAddress::getSize(){
    return items;
}
void OpenAddress::resize(){
    string *temp=hashTable;
    hashTable=new string[tableSize*2];
    tableSize=tableSize*2;
    items=0;
    for (long n=0;n<tableSize/2;n++){
        if (temp[n]!=""){
            insertItem(temp[n]);
        }
    }
    delete [] temp;
}
void OpenAddress::insertItem(string word){
    if (items > tableSize/2){
        resize();
        insertItem(word);
    }else{
        items++;
        int hsh=hash(word);
        if (hashTable[hsh]==""){
            hashTable[hsh]=word;
        }else{
            while (hashTable[hsh]!=""){
                hsh=(hsh+1)%tableSize;
            }
            hashTable[hsh]=word;
            collisions++;
        }
    }
}
string OpenAddress::lookUp(string word){
    int hsh=hash(word);
    if (hashTable[hsh]==word){
        return hashTable[hsh];
    }else {
        while (hashTable[hsh]!=word){
            hsh=(hsh+1)%tableSize;
        }
        return hashTable[hsh];
    }
}
int OpenAddress::Collisions(){
    return collisions;
}
void OpenAddress::print(){
    for (long n=0;n<tableSize;n++){
        if (hashTable[n]!="")
            cout<<hashTable[n]<<endl;
    }
}


