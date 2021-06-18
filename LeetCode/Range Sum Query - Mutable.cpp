class NumArray {
public:
    vector <int> tree;
    int n;
    void buildTree(vector <int> &nums,int l,int r,int idx){
        if (l==r){
            tree[idx]=nums[l];
            return;
        }
        int m=l+(r-l)/2;
        buildTree(nums,l,m,idx*2+1);
        buildTree(nums,m+1,r,idx*2+2);
        tree[idx]=tree[idx*2+1]+tree[idx*2+2];
    }
    
    void treeUpdate(int index,int val,int s,int e,int idx){
        if (s==e){
            tree[idx]=val;
            return;
        }
        int m=s+(e-s)/2;
        if (index<=m){
            treeUpdate(index,val,s,m,idx*2+1);
        }
        else{
            treeUpdate(index,val,m+1,e,idx*2+2);
        }
        tree[idx]=tree[idx*2+1]+tree[idx*2+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n,0);
        buildTree(nums,0,n-1,0);
        // for (int i=0;i<4*n;i++){
        //     cout<<tree[i]<<" ";
        // }
    }
    
    void update(int index, int val) {
        treeUpdate(index,val,0,n-1,0);
    }
    int solve(int s,int e,int l,int r,int idx){
        if (s>r or e<l){
            return 0;            
        }
        if (s<=l and e>=r){
            return tree[idx];
        }
        int m=l+(r-l)/2;
        return solve(s,e,l,m,idx*2+1)+solve(s,e,m+1,r,idx*2+2);
    }
    int sumRange(int left, int right) {
        return solve(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */