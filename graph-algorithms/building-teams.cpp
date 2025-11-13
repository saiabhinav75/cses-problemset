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
const int iter[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool bfs(vector<vector<int>>& edges,vector<int>& color,int start){
    queue<tuple<int,int>> q;
    q.push({start,1 }); // cur, parent, group;
    color[start] = 1;
    while(q.size()){
        auto [cur,group] = q.front();
        q.pop();
        for(int nbr:edges[cur]){
            if(color[nbr] == 0){
                color[nbr] = 3 - group;
                q.push({nbr,color[nbr]});
            } else if(color[nbr] == group){ // Note: here it shouldn't be parent != cur because the parent can be repeated for the siblings of the tree. This is a Bipartate graph problem;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n + 1);
    vector<int> color(n + 1);
    for(int i = 0;i < m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int start = 1; start <= n; start++) {
        if (color[start] == 0) {
            // BFS from this component
           
            bool cycle = bfs(edges,color,start);
            if(cycle){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }

    }
    for(int i=1; i<= n ;i++)
        cout<<color[i]<<" ";
    return 0;
}

/*

-1 1 1 0 0
1 -1 0 0 0
1 0 -1 0 0
0 0 0 -1 1
0 0 0 1 -1


[1,4], [2,3,5]

*/