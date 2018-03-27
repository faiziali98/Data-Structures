#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <string> // Your Own Implementation
#include <cstring>
#include <cstdlib>
#include<fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

class OpenAddress
{
	private:
	    int items=0;
		long tableSize;
		string *hashTable;				// Include your linked list class for this!
		int a;							// input to the hash function
		int collisions;
	public:
		OpenAddress(int A);
		void Load(char* file);
		int hash(string);
		void print();
		long getSize();
		void resize();
		void insertItem(string word);	// Takes a hash of 'Word' and inserts it into hashTable accordingly
		string lookUp(string word);		// Looks for 'Word' and if found, returns it
		int Collisions(); // Return number of collisions in hashTable.
};
