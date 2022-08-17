class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0] , succProb[i]});
        }
        vector<double>ans(n,0);
        ans[start] = 1;
        queue<pair<int,double>> q;
        q.push({start , 1});
        while(!q.empty()){
            int front = q.front().first;
            double prob = q.front().second;
            q.pop();
            for(int i = 0;i<adj[front].size();i++)
            {
                //cout<<ans[adj[front][i].first]<<" "<<adj[front][i].second<<endl;
                if(ans[adj[front][i].first] < prob*adj[front][i].second){
                    ans[adj[front][i].first] = prob*adj[front][i].second;
                    q.push({adj[front][i].first , ans[adj[front][i].first]});
                }
            }
        }
        return ans[end];
    }
};