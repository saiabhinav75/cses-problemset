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

void dfs(vector<vector<char>>& ch,int i,int j){
    if(i<0 || j < 0 || i == ch.size() || j == ch[0].size())
        return;
    if(ch[i][j] == '#')
        return;

    ch[i][j] = '#';
    for(int it=0;it<4;it++){
        dfs(ch,i+iter[it][0],j+iter[it][1]);
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> building(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>building[i][j];
    
    int ans = 0;
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < m ; j++)
            if(building[i][j] == '.'){
                ans++;
                dfs(building,i,j);
            }

    cout<<ans;
    return 0;
}
/*

5 8 # # # # # # # # # . . # . . . # # # # # . # . # # . . # . . . # # # # # # # # #


5 8
########
#..#...#
####.#.#
#..#...#
########

*/

/*

*/