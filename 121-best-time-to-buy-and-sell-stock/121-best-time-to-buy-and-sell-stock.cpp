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
        int buy = prices[0];
        int profit = 0;
        for(int i = 1 ;i<prices.size() ; i++){
            if(buy > prices[i]){
                buy = prices[i];
            }
            else if(buy < prices[i]){
                profit = max(prices[i] - buy , profit);
            }
        }
        return profit;
    }
};