class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //taking initial count of islands to 0
        int islands = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size() ; j++)
            {
                //island only be found when position on grid is 1
                if(grid[i][j] == '1')
                {
                    //if found add 1 to islands and in dfs change grid value to 2 and also neighbours value to 2
                    islands++;
                    dfs(grid , i , j);
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid, int i , int j)
    {
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size() )
        {
            return;
        }
        if(grid[i][j] == '2' || grid[i][j] == '0')
        {
            return ;
        }
        grid[i][j] = '2';
        
        dfs(grid , i-1 ,j);
        dfs(grid , i , j-1);
        dfs(grid , i + 1 ,j);
        dfs(grid , i , j+1);
    }
};