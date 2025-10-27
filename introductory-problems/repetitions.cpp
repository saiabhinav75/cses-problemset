#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int rep = 0;
    int maxx = 1;
    for(int i=1;i<s.length();i++){
        if(s[i] == s[i-1]){
            if(rep == 0)
                rep = 1;
            rep++;
            if(rep > maxx)
                maxx = rep;
        }
        else rep = 0;
    }
    cout<<maxx;
}