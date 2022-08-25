int mod = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0 ;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1] , roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0] , roads[i][2]});
        }
        priority_queue<pair<long long int,int> , vector<pair<long long int,int>> , greater<pair<long long int,int>> >minh;
        vector<long long int>dist(n , 1e18);
        vector<int>frq(n , 0);
        frq[0] = 1;
        dist[0] = 0;
        minh.push({0,0});
        while(!minh.empty()){
            int front = minh.top().second;
            long long int distance = minh.top().first;
            minh.pop();
            for(int i = 0 ;i<adj[front].size();i++){
                if(dist[adj[front][i].first] > distance + adj[front][i].second){
                    dist[adj[front][i].first] = distance + adj[front][i].second;
                    frq[adj[front][i].first] = frq[front];
                    minh.push({dist[adj[front][i].first] , adj[front][i].first});
                }
                else if(dist[adj[front][i].first] == distance + adj[front][i].second){
                    frq[adj[front][i].first]+=frq[front];
                    frq[adj[front][i].first] = frq[adj[front][i].first]%mod;
                }
            }
        }
        return frq[n-1];
    }
};