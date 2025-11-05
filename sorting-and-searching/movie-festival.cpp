#include "../stdc++.h"
#include<vector>
using namespace std;

bool comparator(vector<int> a,vector<int> b){
    if(a[1] < b[1]) return true;
    else if(a[1] == b[1]) return a[0] < b[0];
    else return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>vec[i][0]>>vec[i][1];
    }
    sort(vec.begin(),vec.end(),comparator);
    int max_count = 1;
    int cur = 0;
    for(int i = 1 ;i < vec.size(); i++){
        if(vec[cur][1] <= vec[i][0]){
            max_count++;
            cur = i;
        }
    }
    cout<<max_count;
}
/*

3 5
5 8
4 9
8 10
*/