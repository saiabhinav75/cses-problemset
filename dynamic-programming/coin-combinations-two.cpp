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

// incomplete
template <typename T>
void printVector(const vector<T>& v){
    for(int i = 0; i<v.size();i++)
        cout<<i<<" ";
    cout<<endl;

    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
}

int main() {
    int n,target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
    vector<ll> dp(target+1);
    dp[0] = 1;
    // sort(coins.begin(),coins.end());
    for(int j = 0; j < n ; j++){ // Note: This loop comes first. These are ordered so, there won't be repetition, the same coin is not repeated at one particular value
        for(int i=0;i<=target;i++){
            if(i + coins[j] <= target){
                dp[i + coins[j]] += dp[i];
                dp[i + coins[j]] %= mod;
            }
        }
    }
    // printVector(dp);

    cout<<dp[target];
    return 0;
}

/*

2 2 5
2 5 2

0 0 1 0 1 0 1 0 1 0 - 2
0 0 1 1 1 0 1 0 1 1 - 3
0 0 1 1 1 1 1 0 1 1 - 5
*/
