//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int solve(vector<int>& arr, int k, int start ,int end,vector<vector<int>>&dp){
        if(start == end){
            return 0;
        }
        if(arr[end] - arr[start] <= k){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans =1 +  solve(arr , k , start + 1 , end,dp);
        ans = min(ans , 1 + solve(arr , k , start ,end-1,dp));
        return dp[start][end] = ans;
    }
    public:
    int removals(vector<int>& arr, int k){
        int n = arr.size();
        vector<vector<int>>dp(n + 1, vector<int>(n+1 , -1));
        sort(arr.begin() , arr.end());
        return solve(arr , k , 0 , n-1,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends