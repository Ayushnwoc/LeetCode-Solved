//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
    int solve(vector<int>&a , int index , int prev){
        if(index == a.size()){
            return 0;
        }
        
        if(dp[index][prev] != -1){
            return dp[index][prev];
        }
        
        //not take
        if(prev == 2){
            return dp[index][prev] = solve(a , index+1 , 0 );
        }
        int ans = solve(a , index+1 , 0);
        // take 
        ans = max(ans , a[index] + solve(a , index+1 , prev+1));
        return dp[index][prev] = ans;
    }
  public:
  int findMaxSum(vector<int>& a){
    dp.resize(a.size() + 1 , vector<int>(3 , -1));
    return solve(a , 0 , 0);
  }
  vector<vector<int>>dp;
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends