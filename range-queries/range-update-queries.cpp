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
    long long min,sum,x_or,val, lazy;
    segmentTree *lChild,*rChild;
    segmentTree(int l,int r){
        this->lBound = l;
        this->rBound = r;
        this->min = INT_MAX;
        this->lazy = 0;
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
        left->val = arr[l];
        return left;
    }
    int mid = (l+r)/2;
    segmentTree* left = buildSegmentTree(l,mid,arr);
    segmentTree* right = buildSegmentTree(mid + 1,r,arr);
    segmentTree* main = new segmentTree(l,r);
    main->val = max(left->val,right->val);
    main->setMembers(left,right);
    return main;
}

ll search(int start, int end, segmentTree *node){
    if (node == NULL)
        return 0;
    if (node->lBound >= start && node->rBound <= end){ // node is overlapped between start and end // Complete Overlap
        return node->val;
    }
    if (node->rBound < start || node->lBound > end){
        return 0;
    }
    ll leftVal = search(start, end, node->lChild);
    ll rightVal = search(start, end, node->rChild);
    return max(leftVal,rightVal);
}

// lazy propagation, updating current node value. 
void lazyScoreUpdate(segmentTree* node){
    if(node->lazy == 0) return;

    node->val += node->lazy;
    node->sum += (node->rBound - node->lBound + 1)*node->lazy;
    node->min += node->lazy;
    
    // passing on the lazy Score to its children nodes
    if(node->lBound != node->rBound){
        if(node->lChild)
            node->lChild->lazy += node->lazy;
        if(node->rChild)
            node->rChild->lazy += node->lazy;
    }
    node->lazy = 0;
}



ll pointQuery(int index, segmentTree *node){
    if (node == NULL) return 0;
    
    lazyScoreUpdate(node);  // Apply pending updates first
    
    // Found the leaf node for this index
    if (node->lBound == node->rBound && node->lBound == index){
        return node->val;  // or node->min, node->sum depending on what you need
    }
    
    // Decide which child to go to
    int mid = (node->lBound + node->rBound) / 2;
    
    if (index <= mid){
        return pointQuery(index, node->lChild);
    } else {
        return pointQuery(index, node->rChild);
    }
}


void rangeUpdate(segmentTree* node, int start, int end, ll updateVal){
    if(!node) return;

    lazyScoreUpdate(node);
    
    // ✅ ADD: No overlap check
    if(node->rBound < start || node->lBound > end){
        return;
    }
    
    // Complete overlap
    if(node->lBound >= start && node->rBound <= end){
        node->lazy += updateVal;
        lazyScoreUpdate(node);
        return;
    }

    // Partial overlap - recurse to children
    rangeUpdate(node->lChild, start, end, updateVal);
    rangeUpdate(node->rChild, start, end, updateVal);

    // Update current node based on children
    if(node->lChild){
        lazyScoreUpdate(node->lChild);
        // node->val = max(node->val, node->lChild->val);  // Update val too
    }
    if(node->rChild){
        lazyScoreUpdate(node->rChild);
        // node->val = max(node->val, node->rChild->val);  // Update val too
    }
    
    node->min = min(node->lChild->min, node->rChild->min);
    node->sum = node->lChild->sum + node->rChild->sum;
    node->x_or = node->lChild->x_or ^ node->rChild->x_or;
    node->val = max(node->lChild->val, node->rChild->val);
}

int main() {
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    segmentTree* tree = buildSegmentTree(0,n-1,arr);
    for(int i = 0; i< q; i++){
        int decision;
        cin>>decision;
        if(decision==1){
            long long a,b,u;
            cin>>a>>b>>u;
            rangeUpdate(tree,a-1,b-1,u);
        }
        else{
            int index;
            cin>>index;
            cout<<pointQuery(index - 1,tree)<<endl;
        }
            
    }
    return 0;
}
/*

8 3 3 2 4 5 1 1 5 3 2 4 1 2 5 1 2 4
*/