#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int prev = -1;
    long long minMoves = 0;
    for(int i = 0; i < n; i++){
        int cur;
        cin>>cur;
        if(i!=0){
            minMoves += cur < prev ? prev - cur : 0;
        }
        prev = cur + (cur < prev ? prev - cur : 0);
    }
    cout<<minMoves;
}