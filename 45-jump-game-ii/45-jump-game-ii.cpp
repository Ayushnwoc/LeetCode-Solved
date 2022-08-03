class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+2 , INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i<n;i++)
        {
            for(int j = i-1;j>=0 ; j--)
            {
                if(nums[j] >= i-j)
                {
                    dp[i] = min(dp[i] , dp[j] + 1);
                }
            }
        }
        return dp[n-1];
    }
    
};




























// int cur = -1, maxi = 0,ans = 0,n=nums.size()-1;
//         int i =0;
//         while(maxi<n)
//         {
//             if(i > cur)
//             {
//                 ans += 1;
//                 cur = maxi;
//             }
//             maxi = max(maxi,i + nums[i]);
//             i++;
//         }
//         return ans;
// int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> jumps(n+2,INT_MAX);
//         jumps[0] = 0;
//         for(int i =1;i<n;i++)
//         {
//             for(int j =0;j<i;j++)
//             {
//                 if(j+nums[j]>=i)
//                 {
//                     jumps[i] = min(jumps[i],jumps[j] + 1);
//                 }
//             }
//         }
//         return jumps[n-1];
//     }