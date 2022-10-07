class Solution {
public:
    int maxProfit(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int> > >dp(n+1 , vector<vector<int>>(2 , vector<int>(k+1,0)));
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy <=1;buy++){
                for(int sell = k-1;sell>=0;sell--){
                    if(buy){
                        dp[ind][buy][sell] = max(prices[ind] + dp[ind+1][0][sell + 1], dp[ind+1][buy][sell]);

                    }
                    else{
                        dp[ind][buy][sell] = max(-prices[ind] + dp[ind+1][1][sell] , dp[ind + 1][buy][sell]);
                    }
                }
            }
        }
        return  max(dp[1][1][0] -prices[0] , dp[1][0][0]) ;
    }
};