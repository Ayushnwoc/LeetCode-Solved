class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        vector<int> v;
        int m = ma[0].size();
        int n = ma.size();
        vector<vector<int>> vis ( n+1 , vector<int> (m+1, 0) );
        int i = 1, row = 0, col = 1;
        v.push_back(ma[0][0]);
        vis[0][0] = 1;
        while(i < m*n)
        {
            while(col < m && vis[row][col-1] == 1 && vis[row][col] == 0)
            {
                v.push_back(ma[row][col]);
                vis[row][col] = 1;
                col++;
                i++;
            }
            col--;
            row++;
            while(row<n && vis[row-1][col] == 1 && vis[row][col] == 0)
            {
                v.push_back(ma[row][col]);
                vis[row][col] = 1;
                row++;
                i++;
            }
            row--;
            col--;
            while(col>=0 && vis[row][col+1] == 1 && vis[row][col] == 0)
            {
                v.push_back(ma[row][col]);
                vis[row][col] = 1;
                col--;
                i++;
            }
            col++;
            row--;
            while(row>=0 && vis[row][col] == 0 && vis[row+1][col] == 1) 
            {
                v.push_back(ma[row][col]);
                vis[row][col] = 1;
                row--;
                i++;
            }
            col++;
            row++;
        }
        return v;
    }
};