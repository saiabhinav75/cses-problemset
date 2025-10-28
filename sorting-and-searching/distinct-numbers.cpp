#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,bool> mapp;
    while(n--){
        int cur;
        cin>>cur;
        mapp[cur] = true;
    }
    cout<<mapp.size();
}