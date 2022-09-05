class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = prices[0];
        int n = prices.size();
        for(int i =0; i<n;i++)
        {
            if(prices[i]<mini)
            {
                mini = prices[i];
            }
            else if ( prices[i] > mini)
            {
                if(i == n-1)
                {
                    ans += prices[i] - mini;
                }
                if(i!=n-1 && prices[i+1] < prices[i] )
                {
                    ans += prices[i] - mini;
                    mini = prices[i+1];
                }
            }
        }
        return ans;
    }
};