//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    void dfs(vector<vector<int>>& grid, int i , int j, int a , int b)
    {
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size() )
        {
            return;
        }
        if(grid[i][j] == 2 || grid[i][j] == 0)
        {
            return ;
        }
        count++;
        grid[i][j] = 2;

        dfs(grid , i-1 ,j, a, b);
        dfs(grid , i , j-1, a , b);
        dfs(grid , i + 1 ,j, a , b);
        dfs(grid , i , j+1, a , b);
        par[i][j] = {a , b};
    }
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int ans = 0 , m =grid.size() , n = grid[0].size() ;
        parent = 0;
        par.resize(m , vector<pair<int,int>>(n , {-1,-1}));
        sz.resize(m , vector<int>(n , -1));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size() ; j++){
                count = 0;
                if(grid[i][j] == 1){
                    dfs(grid , i , j , i , j);
                    parent++;
                    sz[i][j] = count;
                }
                ans = max(ans , sz[i][j]);
            }
        }
        // cout<<ans<<endl;
        vector<vector<int>>dir = {{-1 , 0} , {1 , 0} , {0 , -1} , {0, 1}};
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n ; j++){
                // cout<<par[i][j] << " " <<sz[i][j]<<"  ";
                if(grid[i][j] == 0){
                    map<pair<int,int>,int>ma;
                    for(auto k : dir){
                        int x = i + k[0] , y = j + k[1];
                        if(x >=0 and y>=0 and x < m and y < n and grid[x][y] == 2){
                            ma[par[x][y]] = sz[par[x][y].first][par[x][y].second];
                        }
                    }
                    int temp = 1;
                    for(auto l : ma){
                        // cout<<l.first.first<<" "<<l.first.second<<" "<<l.second<<endl;
                        temp += l.second;
                    }
                    // cout<<i<<" "<<j<<" "<<temp<<endl;
                    ans = max(ans ,temp);
                }
            }
            // cout<<endl;
        }
        return ans;
    }
    int count, parent;
    vector<vector<pair<int,int>>>par ;
    vector<vector<int>>sz;
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends