#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        long long y,x;
        cin>>y>>x;
        long long max = y > x ? y : x; // get the diagonal
        long long diagonalValue = 1 + max*(max - 1);
        if(y == x) cout<<diagonalValue<<endl;
        else if(max&1){
            if(x < y) cout<<diagonalValue - (y-x)<<endl;
            else cout<<diagonalValue + (x-y)<<endl;
        }
        else{
            if(x < y) cout<<diagonalValue + (y-x)<<endl;
            else cout<<diagonalValue - (x - y)<<endl;
        }
    }
}