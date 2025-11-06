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
int mod = 1e9 + 7;

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

    for(int i=0;i<target;i++)
        for(int j = 0; j< n ; j++){
            if(i + coins[j] <= target)
                dp[i + coins[j]] = (dp[i + coins[j]] + 1)%mod;
        }

    cout<<dp[target];
    return 0;
}