//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>parent(V , -1);
        for(int i = 0;i<V;i++){
            if(vis[i] == 1){
                continue;
            }
            queue<int>q;
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty()){
                int f = q.front();
                q.pop();
                for(auto j : adj[f]){
                    if(vis[j] == 1 and parent[f] != j){
                        return true;
                    }
                    else if(vis[j] != 1) {
                        q.push(j);
                        vis[j] = 1;
                        parent[j] = f;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends