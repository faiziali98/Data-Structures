#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

int main (){
    string str;
    cin>>str;
    int j=str.length();
    int a=11;
    int hsh=0;
    for (int n=0; n<word.size(); n++) {
		hsh += (int) word[n] * pow(a,j); //Polynomial Hash Code
		j--;
	}
    return 0;
}
