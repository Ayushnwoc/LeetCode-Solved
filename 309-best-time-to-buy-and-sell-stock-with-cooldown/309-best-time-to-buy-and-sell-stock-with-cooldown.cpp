class Solution {
public:
    int f(int ind , int buy , vector<int>& prices  , vector<vector<int>>&dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        if(buy){
            return dp[ind][buy] = max(prices[ind] + f(ind + 2 , 0 , prices ,dp) , f(ind + 1 , buy , prices,dp));
        }
        return dp[ind][buy] = max(-prices[ind] + f(ind + 1 , 1 , prices,dp) , f(ind + 1 , 0 , prices,dp));
    }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(prices.size() + 1 , vector<int>(2 , -1));
        return max(-prices[0] + f(1 , 1 , prices,dp) , f(1 , 0 , prices,dp));
    }    
};
