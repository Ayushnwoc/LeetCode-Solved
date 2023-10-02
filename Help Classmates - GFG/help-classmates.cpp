//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> nums, int n) 
    { 
        stack<int>s;
        for(int i = 0;i<n;i++){
            while(!s.empty() and nums[i]<nums[s.top()]){
                nums[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            nums[s.top()] = -1;
            s.pop();
        }
        return nums;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends