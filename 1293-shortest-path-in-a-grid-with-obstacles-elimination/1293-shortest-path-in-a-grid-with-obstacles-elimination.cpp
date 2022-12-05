class Solution {
public:
    int shortestPath(vector<vector<int>>& mat, int k) {
        int n = mat.size() , m=mat[0].size();
        vector<vector<int>> dir({{1,0},{0,-1},{-1,0},{0,1}});
        vector<vector<pair<int,int>>>vis(n+1,vector<pair<int,int>>(m+1 ,{0,INT_MAX}));
        queue<vector<int>>q;
        if(mat[0][0]){
            q.push({0,0,k-1,0});
        }
        else{
            q.push({0,0,k,0});
        }
        while(!q.empty()){
            vector<int>temp = q.front();q.pop();
            if(temp[0] == n-1 and temp[1] == m-1){
                return temp[3];
            }
            int a = temp[2] , b = temp[3], i=temp[0] , j = temp[1];
            if(vis[i][j].first >= a and vis[i][j].second <= b){
                continue;
            }
            vis[i][j] = {temp[2] , temp[3]};
            for(int k=0; k<4; k++){
                int x=i+dir[k][0];
                int y=j+dir[k][1];
                if(x>=0 and y>=0 and x<n and y<m){
                    if(mat[x][y]){
                        if(temp[2]){  //cant remove block if no k left
                            q.push({x,y,temp[2]-1, temp[3]+1});
                        }
                    } 
                    else{//no block, just pass through
                        q.push({x,y,temp[2], temp[3]+1});
                    }
                }
            }
        }
        return -1;
    }
    
};