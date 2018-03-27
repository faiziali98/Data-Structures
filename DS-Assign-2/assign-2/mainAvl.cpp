#include "bst.cpp"
#include "avl.cpp"
#include <sstream>
using namespace std;
void Menu();
void AvlStart();
void BstStart();
void Menus();
int main(){
    Menus();
    int a;
    cin>>a;
    if (a==1){
        BstStart();
    }else if (a==2){
        AvlStart();
    }
}
void BstStart(){
    string file;
    cout<<"Enter the file name:"<<endl;
    cin>>file; file=file+".txt";
    ifstream f(file.c_str());
    string line;
    string value;
    string temp;
    int key;
    bst<int> tree;
    int g=0;
    cout<<endl;
    startTimer();
    while (getline(f,line)){
        stringstream ss;
        ss<<line;
        ss>>value;
        while(value[value.length()-1]!='~'){
            ss>>temp;
            value=value+" "+temp;
        }
        value.erase(remove(value.begin(), value.end(), '~'), value.end());
        ss>>key;
        tree.insert(value,key);
        g++;
    }
    cout<<"File loaded successfully. "<<g<<" key/value pairs loaded from the file and "<<endl;
    stopTimer();
    Menu();
    int n;
    cin>>n;
    if (n==1){
        string v;
        int k;
        cout<<"Please enter a value to Enter: "<<endl;
        cin>>v;
        cout<<"Please enter a key to Enter: "<<endl;
        cin>>k;
        tree.insert(v,k);
    }else if (n==2){
        int k;
        cout<<"Please enter a key to search: "<<endl;
        cin>>k;
        startTimer();
        if (tree.search(k)!=NULL)
            cout<<tree.search(k)->value<<endl;
        stopTimer();
    }else if (n==3){
        int k;
        cout<<"Please enter a key to delete: "<<endl;
        cin>>k;
        tree.delete_node(k);
    }else if (n==4){
        int ok;int nk;
        cout<<"Enter the key to update:"<<endl;
        cin>>ok;
        cout<<"Enter the key to update with:"<<endl;
        cin>>ok;
        tree.replace(ok,nk);
    }else if (n==5){
        cout<<tree.height(tree.getroot())<<endl;
    }
}

void AvlStart(){
    string file;
    cout<<"Enter the file name:"<<endl;
    cin>>file; file=file+".txt";
    ifstream f(file.c_str());
    string line;
    string value;
    string temp;
    int key;
    AvL<int> tree;
    int g=0;
    cout<<endl;
    startTimer();
    while (getline(f,line)){
        stringstream ss;
        ss<<line;
        ss>>value;
        while(value[value.length()-1]!='~'){
            ss>>temp;
            value=value+" "+temp;
        }
        value.erase(remove(value.begin(), value.end(), '~'), value.end());
        ss>>key;
        tree.insert(value,key);
        g++;
    }
    cout<<"File loaded successfully. "<<g<<" key/value pairs loaded from the file and "<<endl;
    stopTimer();
    cout<<endl;
    Menu();
    int n;
    cin>>n;
    if (n==1){
        string v;
        int k;
        cout<<"Please enter a value to Enter: "<<endl;
        cin>>v;
        cout<<"Please enter a key to Enter: "<<endl;
        cin>>k;
        tree.insert(v,k);
    }else if (n==2){
        int k;
        cout<<"Please enter a key to search: "<<endl;
        cin>>k;
        startTimer();
        if (tree.search(k)!=NULL)
            cout<<tree.search(k)->value<<endl;
        stopTimer();
    }else if (n==3){
        int k;
        cout<<"Please enter a key to delete: "<<endl;
        cin>>k;
        tree.delete_node(k);
    }else if (n==4){
        int ok;int nk;
        cout<<"Enter the key to update:"<<endl;
        cin>>ok;
        cout<<"Enter the key to update with:"<<endl;
        cin>>ok;
        tree.replace(ok,nk);
    }else if (n==5){
        cout<<tree.nodeHeight(tree.getRoot())<<endl;
    }
}
void Menu(){
    cout<<"- Press 1 to Insert another key/value Pair\n"
    <<"- Press 2 to search for a value using its key\n"
    <<"- Press 3 to delete a key/value pair\n"
    <<"- Press 4 to update the key of an existing value\n"
    <<"- Press 5 to see the current height of the Tree\n"<<endl;
}
void Menus(){
    cout<<"What do you want to select?\n"
    <<"- Press 1 to select BST\n"
    <<"- Press 2 to select AVL\n"<<endl<<endl;
}
