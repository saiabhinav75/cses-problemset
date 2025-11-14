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
#include<unordered_set>
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

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<long long,int>>> weightedGraph(n+1); // distance, node (min heap should sort on distance first)
    vector<long long> distances(n + 1,LONG_MAX);
    for(int i=0;i<m; i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        weightedGraph[a].push_back({c,b});
    }
    
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq; // min heap
    pq.push({0,1});
    distances[1] = 0;
    while(pq.size()){
        pair<ll,int> cur = pq.top();
        pq.pop();
        if(cur.first > distances[cur.second])
            continue;
        for(pair<ll,int> nbr:weightedGraph[cur.second]){
            if(nbr.first + cur.first < distances[nbr.second]){
                distances[nbr.second] = nbr.first + cur.first;
                pq.push({distances[nbr.second],nbr.second});
            }
        }
    }
    for(int i = 1;i<=n;i++)
        cout<<distances[i]<<" ";
    return 0;
}
/*


Input:

3 4
1 2 6
1 3 2
3 2 3
1 3 4
Output:

0 5 2


0 



0 - -
0 6 2


*/
