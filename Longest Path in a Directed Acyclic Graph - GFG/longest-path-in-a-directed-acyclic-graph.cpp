//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            vector<vector<pair<int,int>>>adj(v);
            for(auto i : edges){
                adj[i[0]].push_back({i[1] , i[2]});
            }
            vector<int>dis(v, INT_MIN);
            dis[src] = 0;
            priority_queue<pair<int,int>>q;
            q.push({0 , src});
            while(!q.empty()){
                int f = q.top().second , w = q.top().first;
                q.pop();
                for(auto i : adj[f]){
                    int node = i.first , ew = i.second;
                    if(dis[node] < ew + w){
                        dis[node] = ew + w;
                        q.push({dis[node] , node});
                    }
                }
            }
            return dis;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends