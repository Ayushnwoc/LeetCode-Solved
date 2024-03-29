//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> grid)
    {
        int m = N , n = N , ans = 0;
        vector<vector<int>>dp(m,vector<int>(n , 0));
        for(int i = 0;i<m;i++){
            dp[0][i] = grid[0][i] ;
            ans = max(ans,dp[0][i]);
        }
        
        for(int i = 1;i<m;i++){
            for(int j =0;j<n;j++){
                dp[i][j] = dp[i-1][j] + grid[i][j];
                if(j != 0){
                    dp[i][j] = max(dp[i-1][j-1]+grid[i][j] ,dp[i][j]);
                }
                if(j != n-1){
                    dp[i][j] = max(dp[i-1][j+1]+grid[i][j] ,dp[i][j]);
                }
                ans = max(ans , dp[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends