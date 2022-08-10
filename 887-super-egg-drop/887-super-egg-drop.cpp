class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n + 2, vector<int>(k+2 , -7));
        return solve(k, n, dp);
    }
    int solve(int k , int n, vector<vector<int>>& dp)
    {
        if(k<0 || n<0)
        {
            return 0;
        }
        if(k == 1 || n == 0 || n==1)
        {
            return n;
        }
        if(dp[n][k] != -7)
        {
            return dp[n][k];
        }
        int l = 1 , r = n;
        int ans = 1000000;
        int temp=0;
        while(l<=r)
        {
            int m = (l+r)/2;
            int left = solve(k-1 , m-1 , dp);
            int right = solve(k , n-m, dp);
            temp = 1 + max(left , right);
            if(left<=right)
            {
                l = m + 1;
            }
            else
            {
                r = m-1;
            }
            ans = min(ans , temp);
        }
        return dp[n][k] = ans;
    }
    
};