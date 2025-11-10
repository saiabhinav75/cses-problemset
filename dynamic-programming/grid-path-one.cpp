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

void printMatrix(vector<vector<long long>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    vector<vector<long long>> vec(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            char c = s[j];
            vec[i][j] = c == '.' ? 0 : -1;
        }
    }
    if(vec[0][0] == -1 || vec[n-1][n-1] == -1)
        cout<<0;
    else{
        for(int i=0;i<n;i++){
            if(vec[i][0] != -1)
                vec[i][0] = 1;
            else break;
        }
        for(int i=0;i<n;i++){
            if(vec[0][i] != -1)
                vec[0][i] = 1;
            else break;
        }
        for(int i=1;i<n;i++)
            for(int j=1;j<n;j++){
                if(vec[i][j] != -1)
                    vec[i][j] = (max((ll)0,vec[i-1][j]) + max((ll)0,vec[i][j-1]))%mod;
            }
        cout<<vec[n-1][n-1];
    }
    return 0;
}
/*
4

.... .*.. ...* *...

10
.*......*. ...*...*.. ......*... ...*.*.... ....*..... ..*..*.... ..*....... ....*..*.. *........* ....*.....


10

*.**....*. *......**. ...*..*... ***.*..*.. ***.****** ***..**.*. **........ *.*...***. .**...*... **...**..*

*/