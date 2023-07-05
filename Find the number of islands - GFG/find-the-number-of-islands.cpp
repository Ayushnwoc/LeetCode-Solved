//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i , int j , vector<vector<int>>&vis,vector<vector<char>>& grid,int m,int n){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0' or vis[i][j]){
            return;
        }
        vis[i][j] = 1;
        dfs(i+1 , j , vis , grid,m,n);
        dfs(i-1 , j , vis , grid,m,n);
        dfs(i , j+1 , vis , grid,m,n);
        dfs(i , j-1 , vis , grid,m,n);
        dfs(i+1 , j+1 , vis , grid,m,n);
        dfs(i-1 , j-1 , vis , grid,m,n);
        dfs(i+1 , j-1 , vis , grid,m,n);
        dfs(i-1 , j+1 , vis , grid,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size(), count = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' and vis[i][j] == 0){
                    count++;
                    dfs(i , j , vis , grid,m,n);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends