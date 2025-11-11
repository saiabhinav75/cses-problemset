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

void dfs(vector<vector<char>> &map, int i, int j, string &s, string temp)
{
    cout<<i<<" "<<j<<endl;
    if (i < 0 || j < 0 || i == map.size() || j == map[0].size() || map[i][j] == '#')
        return;
    if (map[i][j] == 'B')
    {

        if(s == "")
            s = temp;
        else if(s.length() > temp.length())
            s = temp;
        return;
    }
    map[i][j] = '#';
    dfs(map, i + 1, j, s, temp + "D");
    dfs(map, i - 1, j, s, temp + "U");
    dfs(map, i, j + 1, s, temp + "R");
    dfs(map, i, j - 1, s, temp + "L");
}


string bfs(vector<vector<char>> &map, int startI, int startJ){

    // Note: passing string for each iteration is bad performance;
    // Note: passing Vector for each iteratin is also bad performance;
    queue<pair<int,int>> q; // queue<pair<pair<int,int>,vector<char>>> is bad, queue<pair<pair<int,int>,string>> is bad. Instead maintain a parent tree 
    vector<vector<pair<int,int>>> visit(map.size(),vector<pair<int,int>>(map[0].size(),{-1,-1}));
    q.push({startI,startJ});
    visit[startI][startJ] = {0,0};
    pair<int,int> root = {startI,startJ};
    while(q.size()){
        pair<int,int> cur = q.front();
        q.pop(); // popping at the beginning has significant performance increase;
        int curI = cur.first;
        int curJ = cur.second;
        if(curI < 0 || curJ < 0 || curI == map.size() || curJ == map[0].size() || map[curI][curJ] == '#'){
            continue;
        }
        // cout<<curI<<" "<<curJ<<endl;
        if(map[curI][curJ] == 'B'){
            pair<int,int> cur = {curI,curJ};
            string answer = "";
            while(cur.first != root.first || cur.second != root.second){
                pair<int,int> parent = visit[cur.first][cur.second];
                if(cur.first == parent.first){
                    if(cur.second < parent.second)
                        answer += "L";
                    else
                        answer += "R";
                }
                else{
                    if(cur.first < parent.first)
                        answer += "U";
                    else
                        answer += "D";
                }
                cur = parent;
            }
            reverse(answer.begin(),answer.end());
            return answer;
        }
        pair<int,int> curParent = {curI,curJ};
        if(curI + 1 < map.size() && map[curI + 1][curJ] != '#' && (visit[curI+1][curJ].first == -1 && visit[curI+1][curJ].second == -1)){
            q.push({curI + 1,curJ});
            visit[curI+1][curJ] = curParent;
        }

        if(curI - 1 >= 0 && map[curI - 1][curJ] != '#' && (visit[curI - 1][curJ].first == -1 && visit[curI - 1][curJ].second == -1)){
            q.push({curI - 1,curJ});
            visit[curI - 1][curJ] = curParent;
        }

        if(curJ + 1 < map[0].size() && map[curI][curJ + 1] != '#' && (visit[curI][curJ + 1].first == -1 && visit[curI][curJ + 1].second == -1)){
            q.push({curI,curJ + 1});
            visit[curI][curJ + 1] = curParent;
        }

        if(curJ - 1 >=0 && map[curI][curJ - 1] != '#' && (visit[curI][curJ - 1].first == -1 && visit[curI][curJ - 1].second == -1)){
            q.push({curI,curJ - 1});
            visit[curI][curJ - 1] = curParent;
        }
    }
    return "NO";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    string path = "";

    for (int i = 0; i < n ; i++)
        for(int j = 0; j < m; j++){
            if(map[i][j] == 'A'){
                path = bfs(map,i,j);
                goto endloop;
            }
        }
    endloop:
        if(path == "NO")
            cout<<"NO";
        else{
            cout<<"YES"<<endl<<path.length()<<endl<<path;
        }
        return 0;
}