#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include<fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

class DoubleHash
{
	private:
		long tableSize;
		string *hashTable;				// Include your linked list class for this!
		int a;							// input to the hash function
		int collisions;
		int items;
	public:
		DoubleHash(int A);
		void Load(char* file);
		long getSize();
		void resize();
		void print();
		void insertItem(string Word);	// Takes a hash of 'Word' and inserts it into hashTable accordingly
		int hash1(string);
		int hash2(string);
		string lookUp(string Word);		// Looks for 'Word' and if found, returns it
		int Collisions(); // Return number of collisions in hashTable.
};
