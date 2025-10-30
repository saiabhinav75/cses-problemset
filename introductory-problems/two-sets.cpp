#include "../stdc++.h"
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sumOfNats = (long long)n * (n+1) / 2;
    if(sumOfNats&1){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    vector<bool> numbers(n);
    long long halfSum = sumOfNats / 2;
    int curIndex = n-1;
    vector<int> array1;
    vector<int> array2;
    while(halfSum > 0){
        if(halfSum - (curIndex + 1) < 0){
            numbers[halfSum - 1] = true;
            array1.push_back(halfSum);
            halfSum = 0;
        }
        else{
            halfSum -= (curIndex + 1);
            numbers[curIndex] = true;
            array1.push_back(curIndex + 1);
            curIndex--;
        }
    }
    for(int i=0;i<numbers.size();i++){
        if(!numbers[i]){
            array2.push_back(i + 1);
        }
    }
    cout<<array1.size()<<endl;

    for(int i:array1)
        cout<<i<<" ";
    cout<<endl;
    cout<<array2.size()<<endl;
    for(int i:array2)
        cout<<i<<" ";
}
/*

8 = 36
18

1 2 3 4 8
5 6 7

11 => 66/2 = 33
1 2 3 4 5 6 7 8 9 10 11

*/