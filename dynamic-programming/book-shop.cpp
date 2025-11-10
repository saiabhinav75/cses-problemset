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

bool comparator(pair<int,int>& a,pair<int,int>& b){
    return (a.second - a.first) < (b.second - b.first);
}
int maxPrice = 0;

int recurse(int curIndex,vector<int>& prices,vector<int>& pages,int curPrice,vector<vector<int>>& dp){
    if(curIndex == prices.size()){
        return 0;
    }
    if(dp[curIndex][curPrice] != 0){
        return dp[curIndex][curPrice];
    }
    if(curPrice == maxPrice){
        return 0;
    }
    int k = 0;
    if(curPrice + prices[curIndex] <= maxPrice){
        k = pages[curIndex] + recurse(curIndex + 1, prices, pages, curPrice + prices[curIndex], dp);
    }
    int b = recurse(curIndex + 1, prices, pages, curPrice,dp);
    int curMax = max(k,b);
    return dp[curIndex][curPrice] = curMax;
}

int main() {
    int n,x,maxx;
    maxx = 0;
    cin>>n>>x;
    maxPrice = x;

    vector<int> prices(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n+1,vector<int>(x+1));
    for(int i=0;i<n;i++)
        cin>>prices[i];
    for(int i=0;i<n;i++)
        cin>>pages[i];
    for(int curIndex=n-1;curIndex>=0;curIndex--){
        for(int curPrice = 0;curPrice<x+1;curPrice++){
            int take = 0;
            if(curPrice + prices[curIndex] <= maxPrice){
                take = pages[curIndex] + dp[curIndex + 1][curPrice + prices[curIndex]];
            }
            int skip = dp[curIndex + 1][curPrice];
            dp[curIndex][curPrice] = max(take,skip);
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<x+1;j++)
            maxx = max(maxx,dp[i][j]);
    }
    cout<<maxx<<endl;
    // lets do tabulation later.

    return 0;
}
/*

Input:

4 10 
4 8 5 3 
5 12 8 1

10 10 1 2 10 6 5 1 7 4 10 4 6 3 8 1 7 3 8 6 5 6

*/