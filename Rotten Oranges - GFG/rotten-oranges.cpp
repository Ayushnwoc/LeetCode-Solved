//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        queue<pair<pair<int,int>, int >>q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int tm = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            tm = max(tm , t);
            q.pop();
            if(i + 1 < n and grid[i+1][j] == 1 and vis[i+1][j] == 0 ){
                q.push({{i+1 , j} , t + 1});
                vis[i+1][j] = 2;
            }
            if(j+1 < m and grid[i][j+1] == 1 and vis[i][j+1] == 0){
                q.push({{i, j+1} , t + 1});
                vis[i][j+1] = 2;
            }
            if(i - 1 >=0 and grid[i-1][j] == 1 and vis[i-1][j] == 0){
                q.push({{i-1 , j} , t + 1});
                vis[i-1][j] = 2;
            }
            if(j - 1 >= 0 and grid[i][j-1] == 1 and vis[i][j-1] == 0){
                q.push({{i , j-1} , t + 1});
                vis[i][j-1] = 2;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 and vis[i][j] != 2){
                    return -1;
                }
            }
        }
        return tm;
    }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends