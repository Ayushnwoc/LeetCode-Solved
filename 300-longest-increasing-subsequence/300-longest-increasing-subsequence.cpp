class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int>dp;
        int ans = 1;
        int n = arr.size();
        dp.push_back(arr[0]);
        for(int i = 1;i<n;i++){
            if(arr[i] > dp[ans-1]){
                ans++;
                dp.push_back(arr[i]);
            }
            else{
                int ind = lower_bound(dp.begin() , dp.end() , arr[i]) - dp.begin();
                dp[ind] = arr[i];
            }
        }
        return ans;
    }
};