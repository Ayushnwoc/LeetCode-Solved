class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] += 1;
        }
        map<int,int>::iterator itr = m.end();
        itr--;
        int dp[itr->first +2];
        dp[0] = 0;
        dp[1] = m[1];
        for(int i =2;i<itr->first+1;i++)
        {
            dp[i] =max(dp[i-1],dp[i-2] + i*m[i]);
        }
        return max(dp[itr->first-1],dp[itr->first]);
    }
};