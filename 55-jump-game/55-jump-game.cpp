class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1;i<n;i++)
        {
            if(sum < 1)
            {
                return false;
            }
            sum-=1;
            sum = max(sum , nums[i]);
        }
        return true;
    }
};