#define pi pair<int,int>
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>curr(n+1 , 1e9);
        vector<int>prev(n+1 , 1e9);
        vector<vector<int>> adj(n+1);
        for( int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        curr[0] = prev[0] = 0;
        curr[1] = prev[1] = 0;
        priority_queue<pi , vector<pi> , greater<pi> > minh;
        minh.push({0 , 1});
        while(!minh.empty())
        {
            int front = minh.top().second;
            int t = minh.top().first;
            minh.pop();
            for(int i = 0;i<adj[front].size() ; i++){
                if((t/change)%2 != 0){
                   t += change - (t%change);
                }
                
                if(curr[adj[front][i]] > time + t)
                {
                    prev[adj[front][i]] = curr[adj[front][i]];
                    curr[adj[front][i]] = time + t;
                    minh.push({curr[adj[front][i]] , adj[front][i]});
                    int w = t+ time;
                    if((w/change)%2 != 0){
                       w += change - (w%change);
                    }
                    w += time;
                    if((w/change)%2 != 0){
                       w += change - (w%change);
                    }
                    if(prev[adj[front][i]] > w + time)
                    {
                        prev[adj[front][i]] = w + time;
                        minh.push({prev[adj[front][i]] , adj[front][i]});
                    }
                    
                }
                else if(curr[adj[front][i]] < time + t)
                {
                    if(prev[adj[front][i]] > time + t)
                    {
                        prev[adj[front][i]] = time + t;
                        minh.push({prev[adj[front][i]] , adj[front][i]});
                    }
                }
            }
        }
        for(int i = 0;i<=n;i++)
        {
            cout<<prev[i]<<" "<<curr[i]<<endl;
        }
        return prev[n];
    }
};