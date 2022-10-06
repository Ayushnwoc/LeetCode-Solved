class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n = s.length() , m = p.length();
        if( z == 1)
        {
            dp.resize(200 , vector<int>(200 , -1));
        }
        if(s.empty() && p.empty()){
            return 1;
        }
        else if(p.empty()){
            return false;
        }
        else if(s.empty()){
            if(p[m-1] == '*'){
                return isMatch(s , p.substr(0,m-2));
            }
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(p[m-1] == s[n-1] ){
            dp[n][m] = isMatch(s.substr(0 , n-1 ) , p.substr(0,m-1));
        }
        else if(p[m-1] == '.'){
            dp[n][m] = isMatch(s.substr(0 , n-1 ) , p.substr(0,m-1)) ;
        }
        else if(p[m-1] == '*'){
            if( p[m-2] == s[n-1]){
                dp[n][m] = isMatch(s.substr(0 , n-1 ) , p.substr(0,m-2)) | isMatch(s.substr(0 , n-1 ) , p.substr(0,m)) | isMatch(s.substr(0 , n) , p.substr(0,m-2));
            }
            else if(p[m-2] == '.'){
                dp[n][m] = isMatch(s.substr(0 , n-1 ) , p.substr(0,m-2)) | isMatch(s.substr(0 , n-1 ) , p.substr(0,m)) | isMatch(s.substr(0 , n) , p.substr(0,m-2));   
            }
            else{
                dp[n][m] =  isMatch(s.substr(0 , n) , p.substr(0,m-2));
            }
        }
        if(dp[n][m] == -1){
            return false;
        }
        return dp[n][m];
    }
    int z = 1;
    vector<vector<int>>dp;
};