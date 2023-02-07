//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V , false);
        for(int i = 0;i<V;i++){
            if(vis[i] == false){
                if(dfs(i , vis , adj , -1)){
                    return true;
                }
            }
        }
        return 0;
    }
    bool dfs(int ind , vector<bool>&vis , vector<int> adj[] ,int parent){
        if(vis[ind] == true){
            return true;
        }
        vis[ind] = true;
        for(auto v : adj[ind]){
            if(v != parent ){
                if(dfs(v , vis , adj , ind)){
                    return true;
                }
            }
        }return false;
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