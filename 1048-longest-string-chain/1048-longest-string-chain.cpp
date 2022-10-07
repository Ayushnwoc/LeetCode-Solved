class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        sort(words.begin() , words.end() , [](string& first, string& second){
                                            return first.size() < second.size();});
        vector<int>dp(words.size() , 1);
        for(int i = 1;i<words.size();i++){
            string s = words[i];
            for(int j = 0;j<i;j++){
                string t = words[j];
                bool c = false;
                if(s.length() - t.length() == 1){
                    int w = 0 , error = 0;
                    for(int k= 0;k<t.length() ;k++){
                        if(w == s.length()){
                            w++;
                            break;
                        }
                        if(s[w] != t[k]){
                            error++;
                            k--;
                        }
                        w++;
                        if(error > 1 ){
                            c = false ;
                            break;
                        }
                    }
                    if(error == 1 || error == 0){
                        c = true;
                    }
                }
                if(c){
                    dp[i] = max(dp[i] , 1 + dp[j]);
                }
            }
            ans = max(dp[i] , ans);
        }
        return ans;
    }
};