class Solution {
public:
    int time = 0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<vector<int>>adj(n);
        
        for(int i = 0 ;i < conn.size() ;i++ ){
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        for(int i = 0;i<n;i++)
        {
            if(disc[i] == -1)
            {
                dfs(i , adj , low , disc, -1);
            }
        }
        return ans;
    }
    void dfs(int node, vector<vector<int>>&adj , vector<int>&low, vector<int>&disc , int parent){
        low[node] = time;
        disc[node] = time;
        time+=1;
        for(int i = 0;i<adj[node].size() ; i++){
            if(adj[node][i] == parent)continue;
            if(disc[adj[node][i]] == -1)
            {
                dfs(adj[node][i] , adj , low , disc , node);
                low[node] = min(low[node] , low[adj[node][i]]);
                if(low[adj[node][i]]>disc[node]){
                    ans.push_back({node , adj[node][i]});
                }
            }
            else{
                low[node] = min(low[node] , disc[adj[node][i]]);
            }
        }
    }
    vector<vector<int>> ans;
};