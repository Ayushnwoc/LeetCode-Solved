class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        vector<pair<int, pair<int,int> > > v;
        for(int i = 0;i<n;i++)
        {
            for(int j = i + 1 ; j<n;j++)
            {
                v.push_back({abs(p[j][0] - p[i][0]) + abs(p[i][1] - p[j][1]) , {i , j}});
            }
        }
        sort(v.begin() , v.end());
        make(n);
        int ans = 0;
        for(int i = 0;i<v.size();i++)
        {
            if(!join(v[i].second.first , v[i].second.second))
            {
                ans += v[i].first;
            }
        }
        return ans;
    }
    void make(int n)
    {
        parent.resize(n);
        sz.resize(n);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int n)
    {
        if(n == parent[n])
        {
            return n;
        }
        return parent[n] = find_set(parent[n]);
    }
    bool join(int a , int b)
    {
        int x = find_set(a);
        int y = find_set(b);
        if(x == y)
        {
            return true;
        }
        if(x!=y)
        {
            if(sz[x] < sz[y])
            {
                swap(x,y);
            }
            parent[y] = x;
        }
        return false;
    }
    private:
    vector<int> parent;
    vector<int> sz;
};