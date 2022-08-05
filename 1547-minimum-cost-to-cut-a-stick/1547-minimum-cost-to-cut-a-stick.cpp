class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        vector<int>v;
        v.push_back(0);
        for(int i = 0;i<cuts.size();i++)
        {
            v.push_back(cuts[i]);
        }
        v.push_back(n);
        int N = v.size();
        dp.resize(N+1 , vector<int>(n+1 , -1));
        int ans = cut(0 , v.size() -1 , v);
        return ans;
    }
    int cut(int start , int end , vector<int>& cuts)
    {
        if(end - start == 1)
        {
            return 0;
        }
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i = start+1 ; i<end ; i++)
        {
            ans = min(ans , cut(start , i , cuts) + cut(i , end , cuts));
        }
        ans += cuts[end] - cuts[start];
        return dp[start][end] = ans;
    }
    vector<vector<int>>dp;
};