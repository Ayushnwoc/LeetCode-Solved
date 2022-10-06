class Solution {
public:
    int f(int n , int m , string s , string t){
        if(n > 0 and m == 0){
            return n;
        }
        else if(n <= 0 and m > 0){
            return m;
        }
        if(n == 0 and m == 0) return 0;
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(s[n-1] == t[m-1]){
            dp[n][m] =  f(n-1 , m-1 , s , t);
        }
        else{
            int a =1 + min(f(n-1 , m , s, t) , f(n , m-1 , s, t));
            dp[n][m] =  min(a , 1 + f(n-1 , m-1 , s , t));
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length() , m = word2.length();
        dp.resize(n+1 , vector<int>(m+1 , 0));
        for(int i = 1;i<=n;i++){
            dp[i][0] = i;
        }
        for(int i = 1;i<=m;i++){
            dp[0][i] = i;
        }
        for(int i=1 ;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] =  dp[i-1][j-1];
                }
                else{
                    int a =1 + min(dp[i-1][j] , dp[i][j-1]);
                    dp[i][j] =  min(a , 1 + dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    vector<vector<int>>dp;
};