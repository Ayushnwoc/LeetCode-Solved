class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>deg(n , 0);
        vector<vector<int>>adj(n);
        for(int i = 0;i<p.size();i++){
            deg[p[i][0]]++;
            adj[p[i][1]].push_back(p[i][0]);
        }
        map<int,int>m;
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(deg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty() ){
            int f = q.front();
            if(m[f] >= 1){
                return false;
            }
            m[f]++;
            q.pop();
            for(int i = 0;i<adj[f].size();i++){
                deg[adj[f][i]]--;
                if(deg[adj[f][i]] == 0){
                    q.push(adj[f][i]);
                }
            }
        }
        cout<<m.size();
        if(m.size() == n){
            return true;
        }
        return false;
    }
};