struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , 1);
        int maxi = 1;
        vector<vector<int>>v(n + 2, vector<int>(n + 2, 0));
        v[0][1] = 1;
        int index = 0 ;
        for(int i = 1;i<n;i++)
        {
            v[i][1] = 1;
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[i] == 1 + dp[j])
                    {
                        v[i][dp[i]] += v[j][dp[j]];
                    }
                    else if(dp[i] < 1 + dp[j])
                    {
                        dp[i] = max(dp[j]+1,dp[i]);
                        v[i][dp[i]] = v[j][dp[j]];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for(int i = 0 ;i <n;i++){
            ans += v[i][maxi];
        }
        return ans;
    }
};