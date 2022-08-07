class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 2)
        {
            return nums[n-1] == nums[n-2];
        }
        vector<bool>dp(n+1 , false);
        dp[0] = true;
        dp[1] = false;
        dp[2] = false;
        if(nums[0] == nums[1])
        {
            dp[2] = true;
        }
        for(int i = 3;i<=n;i++)
        {
            if(nums[i-1] == nums[i-2] and dp[i-2])
            {
                dp[i] = true;
            }
            if(nums[i-1] == nums[i-2] and nums[i-1] == nums[i-3] and dp[i-3])
            {
                dp[i] = true;
            }
            if(nums[i-1]-nums[i-2] == 1 and nums[i-1]-nums[i-3] == 2 and dp[i-3])
            {
                dp[i] = true;
            }
        }
        return dp[n];
    }
};