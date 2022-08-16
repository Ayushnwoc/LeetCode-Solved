#define ppi pair<int , pair<int , int>>
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        cost.resize(edges.size()+1);parent.resize(n);sz.resize(n);make(n);vector<ppi>v;
        
        for(int i = 0;i<edges.size();i++)
        {
            v.push_back({edges[i][2] , {edges[i][0] , edges[i][1]}});
            m[{edges[i][0] , edges[i][1]}] = i;
            cost[i] = edges[i][2];
        }
        sort(v.begin(), v.end());
        vector<int>ayush(n , 0);
        int originMST = calculateMST(-1 , -1 , n , v);

        vector<int>critical;vector<int>pseudocritical;
        
        for(int i = 0;i<edges.size();i++)
        {
            make(n);
            int mstree = calculateMST(edges[i][0] , edges[i][1] , n , v);
            make(n);
            int nmstree = edges[i][2] + ncalculateMST(edges[i][0] , edges[i][1] , n , v);
            //cout<<originMST<<" "<<mstree<<" "<<nmstree<<endl;
            if(originMST < mstree || mstree == -1)
            {
                critical.push_back(i);
            }
            if(originMST == mstree && originMST == nmstree)
            {
                pseudocritical.push_back(i);
            }
        }
        return {critical , pseudocritical};
    }
    int calculateMST(int a , int b , int n , vector<ppi>&v)
    {
        int weight = 0;
        for(int i = 0;i<v.size();i++)
        {
            if(v[i].second.first ==a && v[i].second.second ==b)
            {
                continue;
            }
            else
            {
                if(!unionfind(v[i].second.first, v[i].second.second))
                {
                    weight += v[i].first;
                }
            }
        }
        for(int i =0;i<n;i++)
        {
            if(sz[i] == n) 
            {
                return weight;
            }
        }
        return -1;
    }
    int ncalculateMST(int a , int b , int n , vector<ppi>&v)
    {
        unionfind(a , b);
        int weight = 0;
        for(int i = 0;i<v.size();i++)
        {
            if(v[i].second.first ==a && v[i].second.second ==b)
            {
                continue;
            }
            else
            {
                if(!unionfind(v[i].second.first, v[i].second.second))
                {
                    weight += v[i].first;
                }
            }
        }
        for(int i =0;i<n;i++)
        {
            if(sz[i] == n) 
            {
                return weight;
            }
        }
        return -1;
    }
    private:
    map<pair<int,int> , int>m;
    vector<int>cost;
    vector<int>parent;
    vector<int>sz;
    void make(int n)
    {
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int findset(int v)
    {
        if(v == parent[v])
        {
            return v;
        }
        return parent[v] = findset(parent[v]);
    }
    bool unionfind(int a , int b){
        a = findset(a);
        b = findset(b);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            parent[b] = a;
            sz[a] += sz[b];
            return false;
        }
        return true;
    }
};