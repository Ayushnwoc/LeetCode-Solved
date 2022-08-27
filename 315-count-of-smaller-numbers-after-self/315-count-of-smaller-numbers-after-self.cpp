class Solution {
public:
    vector<int>segtree;
    vector<int> countSmaller(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        int mini = INT_MAX , maxi =INT_MIN ;
        for(int i = 0;i<n;i++)
        {
            mini = min(nums[i] , mini);
            maxi = max(maxi , nums[i]);
        }
        for(int i = 0;i<n;i++)
        {
            nums[i] += abs(mini);
            m[nums[i]]++;
        }
        int siz = abs(mini) + abs(maxi);
        cout<<siz<<endl;
        segtree.resize(4*(siz+1) , 0);
        build(0 ,0 , siz , m);
        vector<int>ans;
        for(int i = 0;i<n;i++){
            update(0 ,nums[i] , 0 , siz);
            ans.push_back(query( 0 ,0 , siz , 0 , nums[i]-1));
        }
        return ans;
    }
    void build(int node , int start , int end , map<int,int>&m){
        if(start == end){
            segtree[node] = m[start];
            return;
        }
        int mid = (start+end)/2;
        build(2*node + 1 , start , mid , m);
        build(2*node + 2 , mid + 1 , end , m);
        segtree[node] = segtree[2*node + 1] + segtree[2*node + 2];
    }
    void update(int node ,int val , int start , int end){
        if(segtree[node] == 0){
            return;
        }
        //cout<<1<<endl;
        if(start == end){
            segtree[node] -= 1;
            if(segtree[node] < 0){
                segtree[node] = 0;
            }
            return;
        }
        //cout<<1<<endl;
        int mid = (start + end)/2;
        if(val <= mid){
            update(2*node + 1 , val , start , mid );
        }
        else{
            update(2*node + 2 , val , mid+1 , end );
        }
        segtree[node] = segtree[2*node + 1] + segtree[2*node + 2];
    }
    int query(int node , int start , int end , int i , int j){
        if(segtree[node] == 0){
            return 0;
        }
        if(start > j || i> end)return 0;
        if(i<=start && j>=end){
            return segtree[node];
        }
        if(segtree[node] == 0)
        {
            return 0;
        }
        int mid = (start + end)/2;
        return query(2*node + 1 , start , mid , i , j ) + query(2*node + 2 , mid+1 , end , i , j );
    }
};