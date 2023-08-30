//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    int mod = 1e9 + 7;
    long long int solve(int h) { 
        if(h < 0){
            return 0;
        }
        if(h == 1 or h== 0){
            return 1;
        }
        if(dp[h] != -1){
            return dp[h];
        }
        long long int ans = solve(h-1)*solve(h-1)%mod;
        ans = (ans  + (2*(solve(h-2)*solve(h-1))%mod)%mod)%mod ;
        return dp[h] = ans%mod;
    }
  public:
    long long int countBT(int h) { 
        dp.resize(h+1 , -1);
        return solve(h);
    }
    vector<int>dp;
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends