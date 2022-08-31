class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1 , 0);
        dp[0] = 1;
        dp[1] = 1;
        if(s[0] == '0' ){
            return 0;
        }
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1];
            if(s[i-1] == '0' ){
                if(s[i-2] - '0' > 2 || s[i-2] == '0'){
                    return 0;
                }
                else{
                    dp[i] = dp[i-2];
                    if(dp[i] == 0){
                        dp[i] = 1;
                    }
                }
            }
            else{
                if(s[i-2]-'0' == 2 && s[i-1]-'0'<= 6 && s[i-1]-'0' >= 0){
                    dp[i] += dp[i-2];
                }
                else if(s[i-2]-'0' == 1 &&  s[i-1]-'0' >= 0){
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n];
    }
};