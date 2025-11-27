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
    long long min,sum,x_or,val;
    segmentTree *lChild,*rChild;
    segmentTree(int l,int r){
        this->lBound = l;
        this->rBound = r;
        this->min = INT_MAX;
    }
    void setNodeVal(ll val){
        this->val = val;
    }
    void setMembers(segmentTree* l,segmentTree* r){
        this->lChild = l;
        this->rChild = r;
        this->min = l->min < r->min ? l->min : r->min;
        this->sum = l->sum + r->sum;
        this->x_or = l->x_or ^ r->x_or;
    }
};

segmentTree* buildSegmentTree(int l,int r,vector<int>& arr){
    if(l == r){
        segmentTree* left = new segmentTree(l,l);
        left->min = (ll)arr[l];
        left->x_or = arr[l];
        left->val = (ll)arr[l];
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
        return node->val;
    }
    if (node->rBound < start || node->lBound > end){
        return 0;
    }
    ll leftMin = searchSum(start, end, node->lChild);
    ll rightMin = searchSum(start, end, node->rChild);
    return leftMin | rightMin;
}

void updateTree(int start,int end,ll newVal,segmentTree *node){
    if(node == nullptr)
        return;
    
    // overlap
    if(start == node->lBound && end == node->rBound){
        node->val += newVal;
        return;
    }

    // no overlap
    if(node->rBound < start || node->lBound > end){
        return;
    }

    updateTree(start,end,newVal,node->lChild);
    updateTree(start,end,newVal,node->rChild);
    // if(node->lChild && node->rChild)
    //     node->val += newVal;
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
        cin>>a>>b;
        cout<<searchSum(a - 1,b-1,tree)<<endl;
    }
    return 0;
}
/*
8 4 3 2 4 5 1 1 5 3 2 4 5 6 1 8 3 3

*/