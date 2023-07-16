//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst){
            vector<vector<pair<int,int>>>adj(n+1);
            for(auto i : edges){
                adj[i[0]].push_back({i[1] , 0});
                adj[i[1]].push_back({i[0] , 1});
            }
            queue<pair<int,int>>q;vector<int>vis(n+1,INT_MAX);
            q.push({src,0});
            vis[src] = 0;
            while(!q.empty()){
                int node = q.front().first , ans = q.front().second;
                q.pop();
                for(auto i : adj[node]){
                    int a = i.first , b = i.second;
                    if(vis[a] > ans+b){
                        vis[a] = ans + b;
                        q.push({a ,ans + b});
                    }
                }
            }
            return vis[dst]==INT_MAX?-1:vis[dst];
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends