//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>vis(V, 0);
	    for(int i = 0;i<V;i++){
	        if(!vis[i]){
	            if(!dfs(vis, adj , V, i, 1)){
	                return false;
	            }
	        }
	    }
	    return true;
	}
    bool dfs(vector<int>&vis, vector<int>adj[],int V , int index, int color){
        if(vis[index] ){
            if(vis[index] == color){
                return true;
            }
            return false;
        }
        vis[index] = color;
        if(color == 1 ){
            color = 2;
        }
        else{
            color = 1;
        }
        for(auto i : adj[index]){
            if(!vis[i]){
	            if(!dfs(vis, adj , V, i, color)){
	                return false;
	            }
	        }
	        else{
	            if(vis[i] != color){
	                return false;
	            }
	        }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends