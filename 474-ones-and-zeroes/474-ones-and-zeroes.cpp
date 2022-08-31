class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int w = strs.size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));
        for(int i = 0;i<w;i++){
            int cnt0 = 0, cnt1 = 0;
            for(int j = 0 ;j < strs[i].length();j++){
                if(strs[i][j] == '1'){
                    cnt1++;
                }
                else{
                    cnt0++;
                }
            }
            for(int k = m;k>=cnt0;k--){
                for(int l = n ;l>=cnt1;l--){
                    dp[k][l] = max(dp[k][l] , 1+ dp[k-cnt0][l-cnt1]);
                }
            }
        }
        return dp[m][n];
    }
};