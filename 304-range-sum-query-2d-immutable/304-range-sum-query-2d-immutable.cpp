class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        v.resize(m+1 , vector<int>(n+1 , 0));

        for(int i = 1 ;i<=m;i++){
            for(int j = 1 ;j<=n;j++){
                v[i][j] = matrix[i-1][j-1] + v[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i =row1+1;i<=row2+1;i++)
        {
            ans += (v[i][col2+1] - v[i][col1]  );
        }
        return ans;
    }
    private:
    vector<vector<int>>v;
    vector<vector<int>>mat;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */