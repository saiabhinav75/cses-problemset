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

// Note: Bottom - Top appraoch
int solve(int target, vector<int>& vec){
    vector<int> dp(target + 1,1e7); // using INT_MAX
    dp[target] = 0;
    for(int cur = target; cur >=0; cur--){
        for(int coin: vec){
            if(cur - coin > -1){
                dp[cur - coin] = min(dp[cur - coin],dp[cur] + 1);
            }
        }
    }
    return dp[0] == 1e7 ? -1 : dp[0];
}
int main() {
    int n,target;
    cin>>n>>target;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cout<<solve(target,vec);
    return 0;
}

/*

3 11
1 5 7
0 1 2 3 4 5 6 7 8 9 10 11
        1   1       1   0
      2   2       2

*/