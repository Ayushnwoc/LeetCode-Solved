class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int>z;
        int count = 0;
        int j = 0 , ans = 0;
        z.push_back(0);
        for(int i =0;i<nums.size();i++){
            if(!nums[i]){
                count++;
                z.push_back(i);
            }
            if(count <= k){
                ans = i+1;
            }
            else{
                ans = max(ans , i - z[count-k]);
            }
        }
        return ans;
    }
};