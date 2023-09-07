//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		
    int solve(int cost[],int n ,int w,int index){
        if(index == n or w< 0){
            return 1e5;
        }
        if(w == 0){
            return 0;
        }
        if(dp[index][w] != -1){
            return dp[index][w];
        }
        int ans = solve(cost, n ,w , index+1);
        if(cost[index] == -1){
            return dp[index][w] = ans;
        }
        ans = min(ans , cost[index] + solve(cost, n ,w-(index+1), index) );
        return dp[index][w] = ans;
    }
	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
	    dp.resize(N , vector<int>(W+2 , -1));
	    int ans = solve(cost,N,W,0); 
        return ans >= 1e5 ? -1 : ans;
	} 
	vector<vector<int>>dp;
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends