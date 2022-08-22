class NumArray {
public:
    NumArray(vector<int>& nums) {
        const int N = 1e5+2;
        segtree.resize(4*N , 0);
        v = nums;
        build(0 , 0 , nums.size()-1 );
    }
    void update(int index, int val) {
        updatei(0 , 0 , v.size() - 1 , index , val);
    }
    int sumRange(int left, int right) {
        return querySum(0 , 0 , v.size() - 1 , left , right);
    }
    
    vector<int>segtree;
    vector<int>v;

    //at first start = 0 and end = n-1
    void build(int node , int start , int end){
        if(start == end){
            segtree[node] =v[start];
            return ;
        }
        int mid = (start+end)/2;
        build(2*node + 1 , start , mid);
        build(2*node + 2 , mid+1 , end);

        //this line changes according to need
        segtree[node] = segtree[2*node + 1] + segtree[2*node + 2];
    }
    void updatei(int node , int start , int end , int index , int val){
        if(start == end){
            v[start] = val;
            segtree[node] = val;
            return;
        }
        int mid  = (start + end)/2;
        if(index <= mid)
        {
            updatei(2*node + 1 , start , mid , index , val);
        }
        else
        {
            updatei(2*node + 2, mid + 1 , end, index , val);
        }
        segtree[node] = segtree[2*node + 1] + segtree[2*node + 2];
        return;
    }
    int querySum(int node , int start , int end , int i ,int j){
        if(start > j || i> end){
            return 0;
        }
        if(i<=start && j>=end){
            
            return segtree[node];
        }
        int mid = (start + end)/2;
        return querySum(2*node + 1 , start , mid , i , j ) + querySum(2*node + 2 , mid+1 , end , i , j );
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */