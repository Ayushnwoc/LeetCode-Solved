class Solution {
    
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const int n=grid.size(), m = grid[0].size();
        const vector<pair<int,int>> dirs = {{0,1}, {0, -1}, {1, 0}, {-1,0}};
        deque<tuple<int,int,int>> q; //-dis, i, j
        q.emplace_back(grid[0][0] = -1,0,0);
        while(!q.empty()){
            auto [dis, i, j] = q.front(); q.pop_front();            
            if(i == n-1 && j == m-1) return -dis-1; 
            for(auto [di, dj] : dirs){
                int x = i+di, y = j+dj;
                if(x<0 || x>=n || y<0 || y>=m || grid[x][y] < 0) continue;
                int dis2 = dis - grid[x][y];
                if(dis2 == dis) q.emplace_front(dis2, x, y);
                else q.emplace_back(dis2, x, y);           
                grid[x][y] = dis2;
            }
        }
        return -1;
    }
};