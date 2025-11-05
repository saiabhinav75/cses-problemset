#include "../stdc++.h"
using namespace std;

bool comparator(int a,int b){
    return abs(a) < abs(b);
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n*2);
    for(int i=0;i<n*2;i = i + 2){
        int a,l;
        cin>>vec[i]>>vec[i + 1];
        vec[i + 1] = -1 * vec[i + 1];
    }
    sort(vec.begin(),vec.end(),comparator);
    int cur_count = 0;
    int max_count = 0;
    for(int num:vec){
        cur_count += num > 0 ? 1 : -1;
        max_count = max(max_count,cur_count);
    }
    cout<<max_count;
}
/*

3
5 8
2 4
3 9

2 4
3 9
5 8
*/