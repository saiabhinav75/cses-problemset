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

int k = 0;
void diceCombinations(int target,unordered_map<int,int>& mapp,int cur_sum){
    if(cur_sum == target){
        k += 1;
        return;
    }
    if(mapp[cur_sum]){   
        k += 1;
        return;
    }
    for(int i = 1;i<=6 ;i++){
        if(cur_sum + i <= target){
            diceCombinations(target,mapp,cur_sum + i);
        }
    }
}

long long sumOfVector(vector<long long>& vec){
    long long sum = 0;
    for(int i: vec)
        sum += i;
    return sum%((long long)1e9 + 7);
}
long long solution(int n){
    vector<long long> vec;
    vec.push_back(1);
    // Note: Top - Bottom tabulation
    for(int i = 1;i<=n;i++){
        long long sum = sumOfVector(vec);
        if(vec.size() == 6)
            vec.erase(vec.begin());
        vec.push_back(sum%((long long)1e9 + 7));
    }
    return (vec[vec.size()-1])%((long long)1e9 + 7);
}



int main() {
    int n;cin>>n;
    // diceCombinations(n,mapp,0);
    // cout<<k<<endl;
    cout<<solution(n);
    return 0;
}
/*

0 1 2 3 4
1 1 2 4 8


4
1 3
3 1
2 2
2 1 1
1 1 2
1 2 1
1 1 1 1
*/