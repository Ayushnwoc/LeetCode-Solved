class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<int>>adj(n , vector<int>(n , -1)) ;
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 1e8)) ;
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        for(int k = 0 ;k<n;k++){
            for(int i = 0 ; i<n;i++){
                for(int j = 0 ; j<n;j++){
                    if(adj[i][k] == -1 || adj[k][j] == -1) {
                        continue;
                    }
                    else if(adj[i][j] == -1)
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                    else
                    {
                        adj[i][j] = min(adj[i][j] ,adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        for(int i =0;i<n;i++){
            adj[i][i] =dT+1;
        }
        map<int,vector<int>>m;
        for(int i = 0 ;i<n;i++){
            int ans = 0 ;
            for(int j = 0;j<n;j++){
                if(adj[i][j]<=dT){
                    ans++;
                }
            }
            
            m[ans].push_back(i);
        }
        map<int,vector<int>>::iterator itr = m.begin();
        sort(itr->second.begin() , itr->second.end());
        return itr->second.back();
    }
};