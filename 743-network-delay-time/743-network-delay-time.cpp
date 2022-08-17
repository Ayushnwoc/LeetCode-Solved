#define pi pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector< pair<int, int> >>adj(n+1);
        for(int i = 0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1] , times[i][2]});
        }
        priority_queue<pi , vector<pi> , greater<pi> >minh;
        vector<int>ans(n+1 , 1e9);
        ans[k] = ans[0] = 0;
        minh.push({0 , k});
        while(!minh.empty())
        {
            int front = minh.top().second;
            int time = minh.top().first;
            minh.pop();
            for(int i = 0;i<adj[front].size() ; i++){
                if(ans[adj[front][i].first] > time + adj[front][i].second)
                {
                    ans[adj[front][i].first] = time + adj[front][i].second;
                    minh.push({ans[adj[front][i].first] , adj[front][i].first});
                }
            }
        }
        sort(ans.begin() , ans.end());
        if(ans[n] == 1e9)
        {
            return -1;
        }
        return ans[n];
    }
};