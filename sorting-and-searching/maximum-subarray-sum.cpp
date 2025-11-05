#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
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
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

using namespace std;

int main() {
    long long maxx = INT_MIN;
    long long curSum = 0;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        long long k;
        cin>>k;
        curSum += k;
        maxx = max(maxx,curSum);

        if(curSum < 0)
        curSum = 0;
    }
    cout<<maxx;
    return 0;
}