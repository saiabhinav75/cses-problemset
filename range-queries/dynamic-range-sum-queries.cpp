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

class segmentTree{
    public:
    int lBound,rBound;
    long long sum;
    segmentTree *lChild,*rChild;
    segmentTree(int l,int r){
        this->lBound = l;
        this->rBound = r;
        this->sum = 0;
    }
    void sumNode(int sum){
        this->sum = sum;
    }
    void setMembers(segmentTree* l,segmentTree* r){
        this->lChild = l;
        this->rChild = r;
        this->sum = l->sum + r->sum;
    }
};

segmentTree* buildSegmentTree(int l,int r,vector<int>& arr){
    if(l == r){
        segmentTree* left = new segmentTree(l,l);
        left->sum = (ll)arr[l];
        return left;
    }
    int mid = (l+r)/2;
    segmentTree* left = buildSegmentTree(l,mid,arr);
    segmentTree* right = buildSegmentTree(mid + 1,r,arr);
    segmentTree* main = new segmentTree(l,r);
    main->setMembers(left,right);
    return main;
}

ll searchSum(int start, int end, segmentTree *node){
    if (node == NULL)
        return 0;
    if (node->lBound >= start && node->rBound <= end){ // node is overlapped between start and end // Complete Overlap
        return node->sum;
    }
    if (node->rBound < start || node->lBound > end){
        return 0;
    }
    ll leftSum = searchSum(start, end, node->lChild);
    ll rightSum = searchSum(start, end, node->rChild);
    return leftSum + rightSum;
}

void updateTreeSum(int start,int end,ll newVal,segmentTree *node){
    if(node == nullptr)
        return;
    
    // overlap
    if(start == node->lBound && end == node->rBound){
        node->sum = newVal;
        return;
    }

    // no overlap
    if(node->rBound < start || node->lBound > end){
        return;
    }

    updateTreeSum(start,end,newVal,node->lChild);
    updateTreeSum(start,end,newVal,node->rChild);
    if(node->lChild && node->rChild)
        node->sum = node->lChild->sum + node->rChild->sum;
}

int main() {
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    segmentTree* tree = buildSegmentTree(0,n-1,arr);
    for(int i = 0; i< q; i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        if(a == 2){
            cout<<searchSum(b-1,c-1,tree)<<endl;
        }
        if( a == 1){
            updateTreeSum(b-1,b-1,c,tree);
        }
    }
    return 0;
}

/*
8 4 3 2 4 5 1 1 5 3 2 1 4 2 5 6 1 3 1 2 1 4

*/