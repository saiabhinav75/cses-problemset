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
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> prefixSum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        prefixSum[i] +=( prefixSum[i - 1] + a);
    }
    for(int i=0;i<m;i++){
        int start,end;
        cin>>start>>end;
        cout<<(prefixSum[end] - prefixSum[start - 1])<<endl;
    }
    return 0;
}