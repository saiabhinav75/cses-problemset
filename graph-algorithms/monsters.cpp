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
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, -1, 1};


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m + 1));
    vector<vector<int>> reachTime(n,vector<int>(m,-1)); // monster reach time
    pair<int,int> A_pos;
    queue<tuple<int,int,int>> mQ; // i, j, reachTime
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                A_pos.first = i;
                A_pos.second = j;
            }
            if(grid[i][j] == 'M')
                mQ.push({i,j,0});
        }
    
    while(mQ.size()){
        tuple<int,int,int> cur = mQ.front(); // i, j, reachTime;
        int i = get<0>(cur);
        int j = get<1>(cur);
        int reach = get<2>(cur);
        mQ.pop();
        if(reachTime[i][j] != -1 && reachTime[i][j] < reach)
            continue;
        reachTime[i][j] = reach;
        for(int ind = 0; ind < 4; ind++){
            int n_r = i + dx[ind];
            int n_c = j + dy[ind];
            if(n_r < 0 || n_c < 0 || n_r >= n || n_c >= m || grid[n_r][n_c] == '#' || (reachTime[n_r][n_c] != -1 && reachTime[n_r][n_c] <= reach + 1))
                continue;
            reachTime[n_r][n_c] = reach + 1;
            mQ.push({n_r,n_c,reach + 1});
        }
    }
    mQ.push({A_pos.first,A_pos.second,0});
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{1001,1001}));
    string s = ""; // it is possible to have answer 0 as well;
    bool hasSolution = false;
    // for(int i = 0;i<n;i++){
    //     for(int j =0;j<m;j++){
    //         cout<<reachTime[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(mQ.size()){
        tuple<int,int,int> cur = mQ.front(); // i, j, reachTime;
        int r = get<0>(cur);
        int c = get<1>(cur);
        int reach = get<2>(cur);
        mQ.pop();
        if(r == 0 || c == 0 || r == n-1 || c == m - 1){
            pair<int,int> curIndex = {r,c};
            hasSolution = true;
            vector<char> path;
            while(curIndex.first != A_pos.first || curIndex.second != A_pos.second){
                pair<int,int> cursParent = parent[curIndex.first][curIndex.second];
                if(cursParent.first == curIndex.first){
                    if(cursParent.second < curIndex.second) path.push_back('R');
                    else path.push_back('L');
                }
                if(cursParent.second == curIndex.second){
                    if(cursParent.first < curIndex.first) path.push_back('D');
                    else path.push_back('U');
                }
                curIndex = parent[curIndex.first][curIndex.second];
            }
            reverse(path.begin(),path.end());
            string strPath(path.begin(),path.end());
            s = strPath;
            break;
        }
        if((reachTime[r][c] != -1 && reachTime[r][c] <= reach))
            continue;
        for(int ind = 0; ind < 4; ind++){
            int n_r = r + dx[ind];
            int n_c = c + dy[ind];
            if(n_r < 0 || n_c < 0 || n_r == n || n_c == m || grid[n_r][n_c] == '#' || (reachTime[n_r][n_c] != -1 && reachTime[n_r][n_c] <= reach + 1) || (parent[n_r][n_c].first != 1001 && parent[n_r][n_c].second != 1001) )
                continue;
            mQ.push({n_r,n_c,reach + 1});
            parent[n_r][n_c] = {r,c};
        }
    }
    if(hasSolution){
        cout<<"YES\n"<<s.length()<<endl<<s;
    }
    else cout<<"NO";
    
    return 0;
}