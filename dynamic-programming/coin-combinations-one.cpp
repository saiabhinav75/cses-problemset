#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int mod = 1e9 + 7; // Note: const stores in compile time memory
int main() {
    int n,target;
    cin>>n>>target;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    vector<long long> dp(target + 1);
    dp[0] = 1;
    for (int j = 0; j <= target; j++) {
    for (int coin : vec) {
            if (j + coin <= target) {
                dp[j + coin] += dp[j];
                if (dp[j + coin] >= mod) dp[j + coin] -= mod; // Note: modulo operation is slower operation
            }
        }
    }
    cout<<dp[target];
}