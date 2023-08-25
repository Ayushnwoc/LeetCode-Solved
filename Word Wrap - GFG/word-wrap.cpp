//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(vector<int>nums, int k, int index , int rem){
        if(rem < 0){
            return INT_MAX;
        }
        if(index == nums.size()){
            return 0;
        }
        if(dp[index][rem] != -1){
            return dp[index][rem];
        }
        if(rem == k){
            return dp[index][rem] = solve(nums , k , index+1 , rem - nums[index] );
        }
        else{
            int take = solve(nums , k , index+1 , rem - 1 - nums[index]);
            int notTake = rem*rem + solve(nums , k , index ,k);
            return dp[index][rem] = min(take , notTake);
        }
        return 0;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        dp.resize(nums.size() + 1 , vector<int>(k + 1 , -1));
        return solve(nums , k , 0, k);
    } 
    vector<vector<int>>dp;
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends