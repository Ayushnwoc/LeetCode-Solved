//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<vector<int>>adj(n+1);
            vector<int>indeg(n + 1, 0);
            vector<int>ans(n,INT_MAX);
            for(auto i : edges){
                adj[i[0]].push_back(i[1]);
                indeg[i[1]]++;
            }
            queue<int>q;
            for(int i = 1;i<=n;i++){
                if(indeg[i] == 0){
                    q.push(i);
                    ans[i-1] = 1;
                }
            }
            while(!q.empty()){
                int f = q.front();
                q.pop();
                for(auto i : adj[f]){
                   ans[i-1] = ans[f-1] + 1;
                        indeg[i]--;
                        if(indeg[i] == 0){
                            q.push(i);
                        }
                    
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends