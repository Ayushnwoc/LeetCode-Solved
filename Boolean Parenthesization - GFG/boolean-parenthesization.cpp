//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(string s ,int i , int j, int isTrue){
        int mod= 1003;
        if(i > j){
            return 0;
        }
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }
        if(i == j){
            if(isTrue and s[i] =='T'){
                return 1;
            }
            else if(!isTrue and s[i] == 'F'){
                return 1;
            }
            return 0;
        }
        int ways = 0;
        for(int k = i+1;k<j;k+=2){
            int lt = solve(s , i , k-1 , 1);
            int rt = solve(s , k+1 , j , 1);
            int lf = solve(s , i , k-1 , 0);
            int rf = solve(s , k+1 , j , 0);
            int index = k;
            if(s[index]=='&'){
                if(isTrue){
                    ways= (ways%mod + (lt % mod * rt % mod) % mod ) % mod; 
                }
                else{
                    ways= (ways%mod + (lf % mod * rt % mod)%mod + (lt % mod * rf % mod)%mod + (lf % mod * rf % mod)%mod ) % mod;
                }
            }
            
            else if(s[index]=='|'){
                if(isTrue){
                    ways= (ways%mod + (lf % mod * rt % mod)%mod + (lt % mod * rf % mod)%mod + (lt % mod * rt % mod)% mod )%mod;
                }
                else{
                    ways=(ways%mod + (lf % mod * rf % mod)% mod) % mod;
                }
            }
            else{
                if(isTrue){
                    ways= (ways%mod + (lf % mod * rt % mod)%mod + (lt % mod * rf % mod)% mod) % mod;
                }
                else{
                    ways=(ways%mod + (lt % mod * rt % mod)%mod + (lf % mod * rf % mod)%mod) % mod;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(int N, string s){
        dp.resize(N+1 , vector<vector<int>>(N +1, vector<int>(3, -1)));
        return solve(s , 0 , N-1 , 1);
    }
    vector<vector<vector<int>>>dp;
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends