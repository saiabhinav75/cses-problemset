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
    segmentTree *l_child,*r_child;
    int l_bound,r_bound;
    int min; // minimum
        segmentTree(int l, int u){
            this->l_bound = l;
            this->r_bound = u;
            this->min = INT_MAX;
        }
        void setChildren(segmentTree* l,segmentTree* r){
            this->l_child = l;
            this->r_child = r;
        }
        void setMinimum(){
            if(l_child != NULL && r_child != NULL)
                this->min = l_child->min < r_child->min ? l_child->min : r_child-> min;
        }
};

segmentTree* buildTree(vector<int> &arr,int start,int end){
    if(start == end ){
        segmentTree *mainTree = new segmentTree(start,end);
        mainTree->min = arr[start];
        // cout<<start<<" "<<end<<" "<<mainTree->min<<endl;
        return mainTree;
    }
    int mid = (start + end) / 2;
    segmentTree* left = buildTree(arr,start, mid);
    segmentTree* right = buildTree(arr,mid + 1, end);
    segmentTree* mainTree = new segmentTree(start,end);
    mainTree->setChildren(left,right);
    mainTree->setMinimum();
    // cout<<start<<" "<<end<<" "<<mainTree->min<<endl;
    return mainTree;
}

int searchMin(int start, int end, segmentTree* treeNode){
    if(treeNode == NULL)
        return INT_MAX;
    
    
    // Complete overlap
    if(treeNode->l_bound >= start && treeNode->r_bound <= end){
        return treeNode->min;
    }
    
    // No overlap
    if(treeNode->r_bound < start || treeNode->l_bound > end){
        return INT_MAX;
    }
    
    // Partial overlap - query both children
    int leftMin = searchMin(start, end, treeNode->l_child);
    int rightMin = searchMin(start, end, treeNode->r_child);
    
    return min(leftMin, rightMin);
}
int main() {
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    segmentTree* tree = buildTree(arr,0,n-1);
    for(int i= 0 ;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<searchMin(a - 1,b - 1,tree)<<endl;
    }
    return 0;
}
/*

8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

*/