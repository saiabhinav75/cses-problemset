#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n == 2 || n == 3) {
        cout<<"NO SOLUTION";
        return 0;
    }
    if( n == 4){
        cout<<"2 4 1 3";
        return 0;
    }

    int k = n;
    while(k>0){
        cout<<k<<" ";
        k -= 2;
    }
    k = n-1;
    while(k>0){
        cout<<k<<" ";
        k -= 2;
    }
}