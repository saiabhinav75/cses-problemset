#include "../stdc++.h"
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> applicants(n);
    vector<int> apartments(m);
    for(int i=0;i<n;i++)
        cin>>applicants[i];
    for(int i=0;i<m;i++)
        cin>>apartments[i];
    sort(applicants.begin(),applicants.end());
    sort(apartments.begin(),apartments.end());
    int i,j;
    i = j = 0;
    int answer = 0;
    while(i < n && j<m){
        if(abs(applicants[i] - apartments[j]) <= k){
            answer++;
            i++;
            j++;
        }
        else if(applicants[i] < apartments[j]){
            i++;
        }
        else j++;
    }
    cout<<answer;
}
/*

4 3 5
60 45 80 60

45 60 60 80
30 60 75



*/