class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int oind = 0;
        vector<vector<int>>dp(n+1);
        dp[0].push_back(nums[0]);
        for(int i = 1;i<n;i++){
            int ind = -1;
            for(int j = 0 ;j<i;j++){
                if(nums[i]%dp[j].back() == 0){
                    if(ind == -1){
                        ind = j;
                    }
                    else{
                        if(dp[j].size() > dp[ind].size()){
                            ind = j;
                        }
                    }
                }
            }
            if(ind != -1){
                for(int j = 0;j<dp[ind].size();j++){
                    dp[i].push_back(dp[ind][j]);
                }
            }
            dp[i].push_back(nums[i]);
            if(dp[i].size() > dp[oind].size()){
                oind = i;
            }
        }
        return dp[oind];
    }
};