class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length() ; 
        vector<int>dp(n+1 , 0);
        int mod = 1e9 + 7;
        dp[0]= 1;
        map<char,int>m;
        for(int i = 1;i<=n;i++){
            dp[i] = ((dp[i-1]%mod)*2)%mod;
            if(m.find(s[i-1]) != m.end()){
                dp[i] = (dp[i] - dp[m[s[i-1]] - 1] + mod)%mod ;
                m[s[i-1]] = i;
            }
            else{
                m[s[i-1]] = i;
            }
        }
        return (dp[n] - 1)%mod ;
    }
};