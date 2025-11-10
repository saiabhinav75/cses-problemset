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

int maxDigit(int n){
    int maxx = 0;
    while(n){
        maxx = max(maxx,n%10);
        n /= 10;
    }
    return maxx;
}

int main() {
    int n;
    cin>>n;
    int c = 0;
    while(n){
        n -= maxDigit(n);
        c++;
    }
    cout<<c;
    return 0;
}