class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<vector<char>>v(numRows);
        int j = 0;
        bool val = true;
        for(int i= 0;i<s.length();i++){
            v[j].push_back(s[i]);
            if(val == true){
                j++;
            }
            else{
                j--;
            }
            if(j == numRows){
                val = false;
                j-=2;
            }
            else if(j == -1){
                val = true;
                j+=2;
            }
        }
        string ans;
        for(int i = 0;i<numRows;i++){
            for(int j = 0;j<v[i].size();j++){
                ans += v[i][j];
                cout<<v[i][j]<<" ";
            }cout<<endl;
        }
        return ans;
    }
};