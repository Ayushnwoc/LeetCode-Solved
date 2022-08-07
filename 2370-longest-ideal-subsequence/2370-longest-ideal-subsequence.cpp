class Solution {
public:
    int longestIdealString(string s, int k) {
        int ss = s.size();
        vector<int>dp(26 , 0);
        int ans = 0;
        for(int i = 0;i<ss;i++)
        {
            int temp = s[i] -'a';
            for(int j = max(temp-k ,0);j<=min(25,temp+k);j++)
            {
                dp[temp] = max(dp[temp] , dp[j]);
            }
            dp[temp] += 1;
            ans = max(dp[temp] ,ans);
        }
        return ans;
    }
};