class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool color = true;
        vector<int> vis(n , 0);
        for(int i = 0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                dfs(i , vis , graph , 1 , color);
                if(color == false)
                {
                    return color;
                }
            }
        }
        return color;
    }
    void dfs(int node , vector<int> &vis , vector<vector<int>>& graph , int val , bool& color)
    {
        if(vis[node] ==1 and m[node] != val)
        {
            color = false;
            return;
        }
        if(vis[node] ==1 and m[node] == val)
        {
            return;
        }
        vis[node] = 1;
        m[node] = val;
        if(val == 1) 
        {   
            val = 2;
        }
        else
        {
            val = 1;
        }
        for(int j = 0 ;j <graph[node].size();j++)
        {
            dfs(graph[node][j] , vis , graph , val , color);
        }
    }
    map<int , int>m;
};