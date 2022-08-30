class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size() , n= matrix[0].size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1,0));
        int ans =0 ;
        for(int i = 0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j];
                    ans += dp[i][j];
                    continue;
                }
                if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1]));
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};