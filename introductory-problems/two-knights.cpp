#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(long long num = 1;num<=n;num++){
        long long totalCombinations = (num*num)*(num*num - 1) / 2;
        long long value = (num - 1)*(num-2)/2;
        long long diff = 8 * value;
        long long answer = totalCombinations - diff;
        cout<<answer<<endl;
    }
}