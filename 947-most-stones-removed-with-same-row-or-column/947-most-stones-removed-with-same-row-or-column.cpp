class Solution {
public:
    vector<int>parent;
    vector<int>sz;
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int ,vector<int>>rows,cols;
        for(int i = 0;i<stones.size();i++){
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        sz.resize(stones.size() ,1);
        for(int i =0;i<stones.size();i++){
            parent.push_back(i);
        }
        for(int i = 0 ;i<stones.size();i++){
            for(int j = 0;j<rows[stones[i][0]].size();j++){
                unio(i , rows[stones[i][0]][j]);
            }
            for(int j = 0;j<cols[stones[i][1]].size();j++){
                unio(i , cols[stones[i][1]][j]);
            }
        }
        unordered_set<int>s;
        for(int n : parent){
            s.insert(find(n));
        }
        return stones.size() - s.size();
    }
    int find(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = find(parent[n]);
    }
    void unio(int a , int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};