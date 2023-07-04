//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>indeg(V,0);
	    for(int i = 0;i<V;i++){
	        for(auto j : adj[i]){
	            indeg[j]++;
	        }
	    }
	    queue<int>q;
	    for(int i = 0;i<V;i++){
	        if(!indeg[i]){
	            q.push(i);
	        }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int f = q.front();
	        ans.push_back(f);
	        q.pop();
	        for(auto i : adj[f]){
	            indeg[i]--;
	           // if(indeg[i] < 0 ){
	           //     return true;
	           // }
	            if(indeg[i] == 0){
	                q.push(i);
	            }
	        }
	    }
	    if(ans.size() != V){
	        return true;
	    }
	    return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends