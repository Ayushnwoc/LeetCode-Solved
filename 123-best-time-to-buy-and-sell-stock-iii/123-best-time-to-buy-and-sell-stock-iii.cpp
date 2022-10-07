class Solution {
public:
    vector<vector<vector<int> > >dp;
    int f(int ind , int buy  , int sell , vector<int>&prices){
        if(sell == 2 || ind == prices.size()){
            return 0;
        }
        if(dp[ind][buy][sell] != INT_MIN){
            return dp[ind][buy][sell];
        }
        if(buy){
            dp[ind][buy][sell] = max(prices[ind] + f(ind+1 , 0 , sell + 1 , prices) , f(ind+1 , buy , sell , prices));
            return dp[ind][buy][sell];
        }
        dp[ind][buy][sell] = max(-prices[ind] + f(ind+1 , 1 , sell , prices) , f(ind + 1, buy , sell , prices));
        return dp[ind][buy][sell];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1 , vector<vector<int>>(2 , vector<int>(3,INT_MIN)));
        int ans = max(-prices[0] + f(1 , 1 , 0 , prices) , f(1 , 0 , 0 , prices));
        return  ans;
    }
};