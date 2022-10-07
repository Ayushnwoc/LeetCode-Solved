class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.length();
        int dp[2][2] ={{0}};
        int mod = 1e9+7;
        for(int i = 1;i<=n;i++){
            if(binary[i-1] == '0'){
                dp[0][0] = 1;
                dp[1][0] = (dp[1][1] + dp[1][0])%mod;
            }
            else{
                dp[1][1] = (dp[1][1] + dp[1][0] + 1)%mod;
            }
        }
        return (dp[0][0] + dp[1][1] + dp[1][0])%mod;
    }
};