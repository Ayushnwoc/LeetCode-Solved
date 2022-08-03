class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        int dp[n+2];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i =2;i<n-1;i++)
        {
            int pick = nums[i] + dp[i-2];
            int notpick = dp[i-1];
            dp[i] = max(pick,notpick);
        }
        int ans1 = max(dp[n-2],dp[n-3]);
        dp[1] = nums[1];
        dp[2] = max(nums[1],nums[2]);
        for(int i =3;i<n;i++)
        {
            int pick = nums[i] + dp[i-2];
            int notpick = dp[i-1];
            dp[i] = max(pick,notpick);
        }
        int ans2 = max(dp[n-1],dp[n-2]);
        return max(ans1,ans2);
    }
};