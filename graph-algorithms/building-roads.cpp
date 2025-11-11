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

void dfs(vector<vector<int>>& edges,int i,vector<bool>& visit){
    visit[i] = true;
    for(int k:edges[i]){
        if(!visit[k]){
            dfs(edges,k,visit);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<bool> visit(n);
    vector<int> cycleInit;
    for(int i = 1;i<=n;i++){
        if(!visit[i]){
            cycleInit.push_back(i);
            dfs(edges,i,visit);
        }
    }
    
    cout<<(cycleInit.size() - 1)<<endl;
    for(int i = 1;i<cycleInit.size();i++){
        cout<<cycleInit[i]<<" "<<cycleInit[i-1]<<endl;
    }
    return 0;
}

/**

0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0


0 1, 1 0
2 3, 3 2

1 2 2 1

0 1 0 0
1 0 0 1
0 0 0 1
0 0 0 0
 */