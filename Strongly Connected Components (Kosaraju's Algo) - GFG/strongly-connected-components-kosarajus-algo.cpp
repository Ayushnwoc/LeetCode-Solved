//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<vector<int>>revers(V);
        for(int i = 0 ; i<V; i++){
            for(int j = 0;j<adj[i].size();j++ ){
                revers[adj[i][j]].push_back(i);
            }
        }
        stack<int>st;vector<int>vis(V,0);
        for(int i = 0;i<V;i++){
            dfs(i , adj , st , vis);
        }
        vector<int>visi(V, 0);
        int cnt = 0;
        while(!st.empty()){
            while(st.size() > 0 && visi[st.top()] == 1 )
            {
                st.pop();
            }
            if(st.empty())
            {
                return cnt;
            }
            int front = st.top();
            st.pop();
            dfsi(front , visi ,revers );
            cnt++;
        }
        return cnt;
    }
    void dfsi(int node , vector<int>&visi , vector<vector<int>>&revers)
    {
        visi[node] = 1;
        for(int i = 0;i<revers[node].size();i++){
            if(visi[revers[node][i]] != 1){
                dfsi(revers[node][i] , visi , revers);
            }
        }
    }
    void dfs(int node , vector<vector<int>>&adj , stack<int>&st , vector<int>&vis){
        if(vis[node] == 1)
        {
            return;
        }
        vis[node] = 1;
        for(int i = 0;i<adj[node].size();i++){
            if(vis[adj[node][i]] == 0)
            {
                dfs(adj[node][i] , adj , st , vis);
            }
        }
        st.push(node);
        return;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends