class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin() , coins.end());
        vector<vector<int>>dp (n+1, vector<int>(amount + 1 , INT_MAX-1));
        
        for(int i = 0 , j = 0;i<=n ;i++)
        {
            dp[i][j] = 0;
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=amount;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=coins[i-1])
                {
                    dp[i][j] = min(dp[i][j] , 1 +dp[i][j-coins[i-1]]);
                }
            }
        }
        if(dp[n][amount] >= INT_MAX - 1)
        {
            return -1;
        }
        return dp[n][amount];
    }
};
/*
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort( coins.begin() , coins.end() );
        long long int ans = 0;
        dp.resize(n+1 , vector<long long int>(amount + 1 , 1e9));
        ans =  findmin(coins, n-1 , amount );
        if(ans == INT_MAX || ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
    long long int findmin(vector<int>&coins , int n ,int amount)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(amount < 0 || n<0)
        {
            return INT_MAX;
        }
        if(dp[n][amount] != 1e9)
        {
            return dp[n][amount];
        }
        if(amount >= coins[n])
        {
            dp[n][amount] = 1 + findmin(coins , n , amount -coins[n] );
        }
        return dp[n][amount] = min(dp[n][amount] , findmin(coins , n - 1, amount ));
    }
    vector<vector<long long int>>dp;
    */