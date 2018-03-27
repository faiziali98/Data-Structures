#include "Chaining.cpp"
#include "doubleHash.cpp"
#include "openAddress.cpp"
#include "time.h"

int main(){

    ifstream read;
    vector <string> dict;
    read.open("dict.txt");

    while(!read.eof()){
        string Buffer;
        getline(read,Buffer,'\n');
        dict.push_back(Buffer);
    }

    read.close();
    ofstream out("Collisions.txt");
    ofstream out1("Time.txt");
    cout<<"Processing...."<<endl;

    for (int n=34;n<=50;n++){
        HashC obj1(n);
        obj1.Load("dict.txt");
        out1<<n<<" ";
        startTimer();
        for(int i = 0 ; i < dict.size() ; i++)
            obj1.lookup(dict[i]);
        stopTimer(out1);
        OpenAddress obj2(n);
        obj2.Load("dict.txt");
        startTimer();
        for(int i = 0 ; i < dict.size() ; i++)
            obj2.lookUp(dict[i]);
        stopTimer(out1);
        DoubleHash obj3(n);
        obj3.Load("dict.txt");
        startTimer();
        for(int i = 0 ; i < dict.size() ; i++)
            obj3.lookUp(dict[i]);
        stopTimer(out1);
        cout<<"Done with "<<n<<endl;
        out1<<endl;
        out<<n<<" "<<obj1.Collisions()<<" "<<obj2.Collisions()<<" "<<obj3.Collisions()<<endl;
    }

    cout<<"Successful"<<endl;
    out.close();
    out1.close();

    dict.clear();
    read.open("queries.txt");

    while(!read.eof()){
        string Buffer;
        getline(read,Buffer,'\n');
        dict.push_back(Buffer);
    }

    read.close();
    out.open("Collisions1.txt");
    out1.open("Time1.txt");
    cout<<"Processing...."<<endl;

    for (int n=1;n<=50;n++){
        HashC obj1(n);
        obj1.Load("queries.txt");
        out1<<n<<" ";
        startTimer();
        for(int i = 0 ; i < dict.size() ; i++)
            obj1.lookup(dict[i]);
        stopTimer(out1);
        OpenAddress obj2(n);
        obj2.Load("queries.txt");
        startTimer();
        for(int i = 0 ; i < dict.size() ; i++)
            obj2.lookUp(dict[i]);
        stopTimer(out1);
        DoubleHash obj3(n);
        obj3.Load("queries.txt");
        startTimer();
        for(int i = 0 ; i < dict.size() ; i++)
            obj3.lookUp(dict[i]);
        stopTimer(out1);
        cout<<"Done with "<<n<<endl;
        out1<<endl;
        out<<n<<" "<<obj1.Collisions()<<" "<<obj2.Collisions()<<" "<<obj3.Collisions()<<endl;
    }

    cout<<"Successful"<<endl;
    out.close();
    out1.close();
}


