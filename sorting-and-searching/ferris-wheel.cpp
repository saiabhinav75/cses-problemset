#include "../stdc++.h"
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    sort(vec.begin(),vec.end());
    int i,j,totalRequiredFerries;
    i = totalRequiredFerries = 0;
    j = n-1;
    while(i<=j){
        if(i == j){
            totalRequiredFerries++;
            break;
        }
        if(vec[i] + vec[j] <= x){
            totalRequiredFerries++;
            i++;
            j--;
        }
        else{
            totalRequiredFerries++;
            j--;
        }
    }
    cout<<totalRequiredFerries;
}
/*
Input:
4 10
7 2 3 9
Output:
3
*/