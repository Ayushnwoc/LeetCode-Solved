//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1e9+7;
public:
    int countWays(string s, string str){
        vector<vector<int>>dp(str.length() +1, vector<int>(s.length()+1 , 0));
        for(int i =str.length();i>=0;i--){
            for(int j = s.length();j>=0;j--){
                if(i == str.length()){
                    dp[i][j] = 1;continue;
                }
                if(j == s.length()){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i][j+1]%mod;
                if(str[i] == s[j]){
                    dp[i][j] = (dp[i][j] + dp[i+1][j+1])%mod;
                }
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends