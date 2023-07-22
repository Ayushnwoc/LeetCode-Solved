//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        vector<vector<long long >>dp(n+2 , vector<long long >(2 , 0));
        long long mod = 1e9+7;
        dp[1][0] = 0;
        dp[1][1] = k;
        dp[2][1] = k*(k-1)%mod;
        dp[2][0] = k;
        for(int i = 3;i<=n;i++){
            dp[i][0] = dp[i-1][1]%mod;
            dp[i][1] = (dp[i-1][1]*(k-1) + dp[i-1][0]*(k-1))%mod;
        }
        return (dp[n][0] + dp[n][1])%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends