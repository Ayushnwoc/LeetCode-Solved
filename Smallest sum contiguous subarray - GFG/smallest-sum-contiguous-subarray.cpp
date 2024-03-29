//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& nums){
    int sum = 0;
    int ans = INT_MIN;
    for(int i = 0;i<nums.size(); i++)
    {
        sum += -nums[i];
        ans = max(ans , sum);
        if(sum < 0 ){
            sum = 0;
        }
    } 
    return -1*ans;
  }
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
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends