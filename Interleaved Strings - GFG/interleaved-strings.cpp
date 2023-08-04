//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    int solve(string a, string b , string c ){
        if(c == ""){
            return 1;
        }
        if(a[0] == c[0] and b[0] == c[0]){
            if(m[a.length()][b.length()] != -1){
                return m[a.length()][b.length()];
            }
            return m[a.length()][b.length()] = max(solve(a.substr(1,a.length()-1) ,b,c.substr(1,c.length()-1)),
            solve(a,b.substr(1,b.length()-1),c.substr(1,c.length()-1)));
        }
        else if(a[0] == c[0]){
            return solve(a.substr(1,a.length()-1) ,b,c.substr(1,c.length()-1));
        }
        else if(b[0] == c[0]){
            return solve(a,b.substr(1,b.length()-1),c.substr(1,c.length()-1));
        }
        return 0;
    }
    bool isInterleave(string A, string B, string C) {
        if(A.length() + B.length() != C.length()){
            return false;
        }
        m.resize(102 , vector<int>(102, -1));
        return solve(A, B,C);
    }
    vector<vector<int>>m;

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends