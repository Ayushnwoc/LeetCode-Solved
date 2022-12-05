class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1,INT_MAX));
        priority_queue<vector<int> , vector<vector<int>>,greater<vector<int>>>q;
        q.push({0,0,0});
        vector<vector<int>>dir({{0,1},{0,-1},{1,0},{-1,0}});
        while(!q.empty()){
            vector<int>t = q.top();q.pop();
            int i = t[1] , j = t[2];
            //cout<<i<<" "<<j<<endl;
            if( i == m-1 and j == n-1 ){
                return t[0];
            }
            if(dp[i][j] <= t[0]){
                continue;
            }
            dp[i][j] = t[0];
            int vv = i +dir[grid[i][j]-1][0],vw=j +dir[grid[i][j]-1][1];
            if(vv>=0 and vw>=0 and vv<m and vw<n){
                q.push({t[0] , vv, vw});
            }
            for(int k = 0;k<4;k++){
                int x = i + dir[k][0] , y = j + dir[k][1];
                if(x >= 0 and y >= 0 and x <m and y<n){
                    if(grid[i][j]-1 != k){
                        q.push({t[0] + 1 , x , y});
                    }
                }
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j =0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m-1][n-1];
    }
};