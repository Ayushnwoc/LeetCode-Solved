class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        map<int,int>m;
        for(int i = 0;i<n;i++)
        {
            m[arr[i]]  = i;
        }
        m[arr[0]] = n;
        int mod = 1e9 + 7;
        vector<long long int> dp (n+1 , 1);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0 ; j<i;j++)
            {
                if(arr[i]%arr[j] == 0)
                {
                    int right = arr[i]/arr[j];
                    
                    if(m[right] != 0)
                    {
                        int temp = m[right];
                        if(temp == n)
                        {
                            temp = 0;
                        }
                        dp[i] = (dp[i] + dp[j]*dp[temp])%(mod);
                        //cout<<dp[i]<<endl;
                    }
                }
            }
        }
        long long int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            //cout<<dp[i]<<endl;
            ans += dp[i];
        }
        return ans%mod;
    }
};