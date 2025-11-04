#include "../stdc++.h"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<pair<int,int> > sett;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        sett.insert({k,i});
    }
    for (int i = 0; i < m; i++)
    {
        int cur;
        cin >> cur;
        auto match = sett.lower_bound({cur + 1,0});
        if(match == sett.begin()){
            cout<<-1<<endl;
        } else{
            match--;
            cout<<(*match).first<<endl;
            sett.erase(match);
        }
    }
}
/*

Input:

5 3
5 3 7 8 5
4 8 3

Output:

3
8
-1


3 5 5 7 8
4 8 3
*/