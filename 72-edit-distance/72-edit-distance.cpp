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
        dp.resize(n+1 , vector<int>(m+1 , -1));
        return f(n , m , word1 , word2);
    }
    vector<vector<int>>dp;
};