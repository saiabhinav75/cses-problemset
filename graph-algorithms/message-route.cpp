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
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

vector<int> bfs(vector<vector<int>>& edges,int n){
    vector<int> visit(edges.size(),-1);
    queue<int> q;
    q.push(1); //start
    visit[1] = 0;
    while(q.size()){
        int cur = q.front();
        q.pop();
        if(cur == n){
            vector<int> path;
            while(cur != 0){
                path.push_back(cur);
                cur = visit[cur];
            }
            reverse(path.begin(),path.end());
            return path;
        }
        for(int next:edges[cur]){
            if(visit[next] == -1){
                q.push(next);
                visit[next] = cur;
            }
        }
    }
    return {};
}

int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> edges(n + 1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> k = bfs(edges,n);
    if(k.size() == 0){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<k.size()<<endl;
    for(int i:k)
        cout<<i<<" ";
    return 0;
}
/*

1 -> 2 3 4
2 -> 1 3
3 -> 1 2
4 -> 1 5
5 -> 4

*/