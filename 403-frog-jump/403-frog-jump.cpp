class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>>dp(n+1 , vector<bool>(n+2, false));
        if(stones[1] != 1 ){
            return 0;
        }
        if(n == 2){
            return true;   
        }
        dp[1][1] = true;
        dp[1][2] = true;
        for(int i = 2;i<n;i++){
            for(int j = 1;j<i;j++){
                int req = stones[i] - stones[j];
                if(req > 0 && req<n && dp[j][req]){
                    if(i == n-1){
                        return true;
                    }
                    dp[i][req] = 1;
                    if(req + 1 < n) dp[i][req+1] = true;
                    if(req - 1 > 0) dp[i][req-1] = true;
                }
            }
        }
        return false;
    }
};