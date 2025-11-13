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


template <typename T>
void printVector(const vector<T>& v){
    for(auto i:v)
    cout<<i<<' ';
    cout<<endl;
}

bool dfs(int start, vector<vector<int>>& edges,vector<int>& visit,int parent){
    for(int nbr:edges[start]){
        if(!visit[nbr]){
            visit[nbr] = start;
            bool k= dfs(nbr,edges,visit,start);
            if(k)
                return true;
        } else if(parent != nbr){
            vector<int> answer;
            answer.push_back(nbr);
            int cur = start;
            while(cur != nbr){
                answer.push_back(cur);
                cur = visit[cur];
            }
            answer.push_back(cur);
            cout<<answer.size()<<endl;
            for(int i:answer){
                cout<<i<<" ";
            }
            return true;
        }
    }
    return false;
}


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n + 1);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> visit(n + 1);
    bool cycle = false;
    for(int start = 1;start<=n;start++){
        if(!visit[start]){
            visit[start] = start;
            if(dfs(start,edges,visit,start)){
                cycle = true;
                break;
            };
        }
    }
    if(!cycle)
        cout<<"IMPOSSIBLE";

    return 0;
}