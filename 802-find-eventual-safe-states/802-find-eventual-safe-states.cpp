class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int,int>safe;
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>v;
        queue<int>q;
        vector<vector<int>>adj(n);
        for(int i = 0;i<n;i++){
            vis[i] = graph[i].size();
            if(vis[i] == 0){
                q.push(i);
                v.push_back(i);
            }
            for(int j = 0;j<vis[i];j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(int i = 0;i<adj[f].size();i++){
                vis[adj[f][i]]--;
                if(vis[adj[f][i]] == 0){
                    q.push(adj[f][i]);
                    v.push_back(adj[f][i]);
                }
            }
        }
        sort(v.begin() , v.end());
        return v;
    }
};