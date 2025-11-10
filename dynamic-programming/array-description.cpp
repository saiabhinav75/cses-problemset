#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
 
long long ans = 0;
int maxVal = 0;
 
template <typename T>
void printVector(const vector<T>& v){
    // for(int i = 0; i<v.size();i++)
    //     cout<<i<<" ";
    // cout<<endl;
 
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
}
 
int recurse(vector<int>& arr,int curIndex,vector<vector<int>>& dp,int prevElem){
    if(curIndex == arr.size()){
        return 1; // returns 1
    }
    if(dp[curIndex][prevElem] != -1){
        return dp[curIndex][prevElem];
    }
    long long summ = 0;
    if(arr[curIndex] > 0){
        if(abs(arr[curIndex] - prevElem)<=1){
            summ = recurse(arr,curIndex + 1,dp,arr[curIndex])%mod;
        }
    }
    else{
        for(int val = max(1, prevElem - 1); val <= min(maxVal, prevElem + 1); val++) { // keeping in bound!
            summ = (summ + recurse(arr, curIndex + 1, dp, val)) % mod;
        }
    }
    return dp[curIndex][prevElem] = summ%mod;
}
 
int main() {
    int n,m;
    cin>>n>>m;
    maxVal = m;
    vector<int> arr(n);
    vector<vector<int>> dp(n,vector<int>(m+1,-1));
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long result = 0;
    if(arr[0]==0){
        for(int i=1;i<=m;i++){
            // DO NOT MODIFY THE ARRAY AT ANY COST
            result += recurse(arr,1,dp,i);
            result %= mod;
        }
    }
    else result = recurse(arr,1,dp,arr[0]);
    cout<<result;
    return 0;
}
 
/*
 
Input: 3 5 2 0 2 output: 3
Input 3 5 0 0 0 output 35
Input 3 4 0 0 0 output 26
 
10 3 0 0 0 1 0 0 0 3 0 0
480
 
 
 
10 10 0 0 0 0 0 0 0 0 0 5
18581
 
10 10 0 0 0 8 0 6 0 0 0 0
2106
 
 
 
2 0 2 0
2 1 2 0
2 2 2 0
2 3 2 0
 
 
2120
-> 2121
-> 2122
-> 2123
 
2 2 2 0
-> 2221
-> 2222
-> 2223
 
2 3 2 0
-> 2321
-> 2322
-> 2323
 
*/
