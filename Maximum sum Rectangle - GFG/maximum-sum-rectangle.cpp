//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int ans = INT_MIN;
        for(int i = 0;i<C;i++){
            vector<int>temp(R,0); 
            for(int j = i;j<C;j++){
               for(int k = 0;k<R;k++){
                   temp[k] += M[k][j];
               }
               ans = max(ans , kadane(temp , R));
            }
        }
        return ans;
    }
    int kadane(vector<int>&arr, int n)
    {
        long long ms = INT_MIN , sum = 0;
        for(int i =0;i<n;i++){
            sum += arr[i];
            ms = max(ms , sum);
            if(sum < 0){
                
                sum = 0;
            }
        }
        return ms;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends