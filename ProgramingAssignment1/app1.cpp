#ifndef __APP2_CPP
#define APP2_CPP
#include "stack.cpp"
using namespace std;

int Fibonacci(int n)
{
   if ( n == 0 ){
        return 0;
   }else if ( n == 1 ){
        return 1;
   }else{
        return ( Fibonacci(n-1) + Fibonacci(n-2) );
   }
}
int Find_F_N(int n){
    Stack<int> st;
    for(int i=0;i<n;i++){
    	st.push(Fibonacci(i));
    }
    int a=st.pop();
    a=a*a;
    for(int i=2;i<=n/2;i++){
    	int temp= st.pop();
    	a = a % temp;
    	a=a*a;
    }
    return a;
}

int main(){
	cout<<Find_F_N(4)<<endl;
}

#endif
