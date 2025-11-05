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

using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    // shouldn't use unordered_map for sortable problems
    map<int,int> mapp;
    vector<int> vec;
    for (int i = 0; i < n; i++){
        int k;
        cin>>k;
        vec.push_back(k);
    }
    bool solution = false;
    for (int i = 0; i < n; i++){
        int k = vec[i];
        if(mapp[k]){
            solution = true;
            cout<<mapp[k]<<" "<<i + 1<<endl;
            break;
        }
        else mapp[target - k] = i + 1;
    }
    if(!solution) cout<<"IMPOSSIBLE"<<endl;
    return 0;
}