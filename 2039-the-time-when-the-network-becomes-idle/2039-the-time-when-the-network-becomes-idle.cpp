class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>>adj(n);
        for(int i = 0 ;i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        priority_queue<pair<int,int> , vector<pair<int ,int>> , greater<pair<int,int>> >minh;
        minh.push({0 ,0});
        vector<int>time(n , 1e8);
        time[0] = 0;
        while(!minh.empty())
        {
            int front = minh.top().second;
            int times =  minh.top().first;
            minh.pop();
            for(int i = 0;i<adj[front].size();i++){
                if(time[ adj[front][i] ] > times + 1){
                    time[adj[front][i]] = times + 1;
                    minh.push({times+1 , adj[front][i]});
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<n;i++){
            int firstTimeReceive = time[i] * 2; // Send to master server, and receive from master server
            int waitingTime = firstTimeReceive - 1;
            int numResend = waitingTime / patience[i];
            int timeDone = firstTimeReceive + numResend * patience[i];
            ans = max(ans, timeDone); 
        }
        return ans+1;
    }
};