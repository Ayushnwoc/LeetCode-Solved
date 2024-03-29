//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int ans = 0 , maxi = 0;
	    for(auto i : S){
	        if(i == '1'){
	            ans--;
	        }
	        else{
	            ans++;
	            maxi = max(ans , maxi);
	        }
	        if(ans <0){
	            ans = 0;
	        }
	    }
	    return maxi==0?-1:maxi;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends