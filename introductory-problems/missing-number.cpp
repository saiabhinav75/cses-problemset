#include<iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long totalSum = (n * (n+1))/2;
    while(--n){
        int cur;
        cin>>cur;
        totalSum -= cur;
    }
    cout<<totalSum;
}