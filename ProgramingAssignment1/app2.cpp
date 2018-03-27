#ifndef __APP3_CPP
#define APP3_CPP
#include "queue.cpp"
#include <fstream>
#include <string>
using namespace std;

bool contains (string one, string two){
	int g=0;
	for (int n=0;n<one.length();n++){
			if (one[n]==two[0]){
                g++;
				for (int n1=1;n1<two.length();n1++){
					if (one[n+n1]==two[n1]){
						g++;
					}else{
						g=0;
						break;
					}
				}
			}
			if (g==two.length())
				return true;
	}
}

Queue<string> FindWords(string str){

	ifstream file("words.txt");
	string line;
	LinkedList<string> temp;
	Queue<string> results;

	while(getline(file,line) != NULL){
		 bool c = contains(line,str);
		 if(c==true)
		 	temp.insertSorted(line);
	}


	ListItem<string> *iter = temp.getHead();
	while(iter != NULL){
		results.enqueue(iter->value);
		iter = iter->next;
	}
	return results;
}

int main(){
    string toSearch;
    cout<<"Enter the word to search:"<<endl;
    cin>>toSearch;
	Queue<string> ans = FindWords(toSearch);
	ans.list.print();
	cout<<ans.list.length()<<endl;
}

#endif
