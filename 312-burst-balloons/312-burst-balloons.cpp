class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> n;
        n.push_back(1);
        for(int i = 0;i<nums.size();i++)
        {
            n.push_back(nums[i]);
        }
        n.push_back(1);
        dp.resize(n.size() + 1 , vector<int>(n.size() + 1, -1));
        return solve (0 , n.size() - 1 , n);
    }
    int solve(int i , int j , vector<int>&nums)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int tem= 0;
        for(int k = i+1 ;k<j;k++)
        {
            tem = max(tem , solve(i , k, nums) + solve(k , j , nums) + nums[i]*nums[k]*nums[j]);
        }
        return dp[i][j] = tem ;
    }
    private:
    vector<vector<int>>dp;
};