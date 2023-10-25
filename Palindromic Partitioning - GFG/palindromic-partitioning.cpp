//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool check(string s){
        // cout<<s<<endl;
        if(s.length() == 1){
            return true;
        }
        int n = s.length();
        for(int i = 0;i<n/2;i++){
            if(s[i] != s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    int solve(string str , int start , int end){
        if(start >= end or check(str.substr(start , end - start + 1))){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = 1000;
        for(int i = start;i<end;i++){
            if(check(str.substr(start , i - start + 1)) == true){
                ans = min(ans , 1 + solve(str , i+1, end));
            }
        }
        return dp[start][end] = ans;
    }
public:
    int palindromicPartition(string str)
    {
        dp.resize(str.length() + 1 , vector<int>(str.length() + 1 , -1));
        return solve(str , 0 , str.length() - 1);
    }
    vector<vector<int>>dp;
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends