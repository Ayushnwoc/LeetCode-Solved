//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    long long solve(string s, int k){
        int n = s.size() , j = 0 , cnt = 0;
        long long ans = 0;
        vector<int>v(26 , 0);
        for(int i = 0;i<n;i++){
            if(v[s[i] - 'a'] == 0){
                cnt++;
            }
            v[s[i] - 'a']++;
            while(cnt > k){
                v[s[j] - 'a']--;
                if(v[s[j] - 'a'] == 0){
                    cnt--;
                }
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
  public:
    long long int substrCount (string s, int k) {
    	return solve(s , k) - solve(s , k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends