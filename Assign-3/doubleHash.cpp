#include "doubleHash.h"


DoubleHash::DoubleHash(int A){
    a=A;
    tableSize=100067;
    collisions=0;
    items=0;
    hashTable=new string [tableSize];
}

void DoubleHash::Load(char* file){
    ifstream ifin;
	ifin.open(file);
	while (!ifin.eof()){
        string word;
        ifin>>word;
        insertItem(word);
	}
}

long DoubleHash::getSize(){
    return items;
}

int DoubleHash::hash2(string word){
    int j=word.length()-1;
    int hsh=0;
    for (int i=0; i<word.size(); i++) {
		hsh += (int) word[i] * pow(a,j); //Polynomial Hash Code
		j--;
	}
    return (abs(hsh)%tableSize);
}

void DoubleHash::resize(){
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

void DoubleHash::insertItem(string word){
    if (items > tableSize/2){
        resize();
        insertItem(word);
    }else{
        items++;
        int hsh1=hash1(word);
        int hsh2=hash2(word);
        if (hashTable[hsh1]==""){
            hashTable[hsh1]=word;
        }else if (hashTable[hsh2]==""){
            hashTable[hsh2]=word;
        }else{
            while (true){
                hsh2=(hsh2+1)%tableSize;
                hsh1=(hsh1+1)%tableSize;
                if (hashTable[hsh1]==""||hashTable[hsh2]=="")
                    break;
            }
            if (hashTable[hsh1]==""){
                hashTable[hsh1]=word;
            }else if (hashTable[hsh2]==""){
                hashTable[hsh2]=word;
            }
            collisions++;
        }
    }
}

int DoubleHash::hash1(string word){
    int Hash1 = 0;
    for (int n=0;n<word.length();n++){
        Hash1 ^= (Hash1 << 5) + (Hash1 >> 2) + word[n];
    }
    return abs(Hash1)%tableSize;
}

string DoubleHash::lookUp(string word){
    int hsh1=hash1(word);
    int hsh2=hash2(word);
    if (hashTable[hsh1]==word){
        return hashTable[hsh1];
    }else if (hashTable[hsh2]==word){
        return hashTable[hsh2];
    }else {
        while (true){
            hsh2=(hsh2+1)%tableSize;
            hsh1=(hsh1+1)%tableSize;
            if (hashTable[hsh2]==word||hashTable[hsh1]==word)
                break;
        }
        if (hashTable[hsh1]==word){
            return hashTable[hsh1];
        }else if (hashTable[hsh2]==word){
            return hashTable[hsh2];
        }
    }
}

int DoubleHash::Collisions(){
    return collisions;
}

void DoubleHash::print(){
    for (long n=0;n<tableSize;n++){
        if (hashTable[n]!="")
            cout<<hashTable[n]<<endl;
    }
}


