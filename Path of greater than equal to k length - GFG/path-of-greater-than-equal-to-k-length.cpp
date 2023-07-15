//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    int dfs(int index , vector<vector<pair<int,int>>>adj , vector<int>vis){
        if(vis[index]){
            return 0;
        }
        vis[index] = 1;
        int ans = 0;
        for(auto i : adj[index]){
            int node = i.first , w = i.second;
            if(!vis[node]){
                ans = max(ans , w + dfs(node , adj , vis));
            }
        }
        return ans;
    }
    bool pathMoreThanK(int V, int e, int k, int *a) { 
        vector<vector<pair<int,int>>>adj(V);
        for(int i = 2;i<3*e;i+=3){
            adj[a[i-2]].push_back({a[i-1] , a[i]});
            adj[a[i-1]].push_back({a[i-2] , a[i]});
        }
        vector<int>vis(V,0);
        int ans = dfs(0 , adj , vis);
        // cout<<ans<<endl;
        return ans>=k;
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends