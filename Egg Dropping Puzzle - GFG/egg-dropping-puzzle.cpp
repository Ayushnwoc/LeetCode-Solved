//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int k, int n) {
        if(k == 1){
            return n;
        }
        if(n <= 1){
            return n;
        }
        if(dp[k][n] != -1){
            return dp[k][n];
        }
        int ans = INT_MAX;
        for(int i = 1;i<=n;i++){
            ans = min(ans , 1 + max(solve(k-1, i-1) , solve(k, n - i) ));
        }
        return dp[k][n] = ans;
    }
    int eggDrop(int k, int n) {
        dp.resize(k+1 , vector<int>(n+1,-1));
        return solve(k , n);
    }
    vector<vector<int>>dp;
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends