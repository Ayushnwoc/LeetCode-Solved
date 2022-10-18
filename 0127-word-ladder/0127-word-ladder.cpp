class Solution {
public:
    int comp(string a , string b){
        int ans = 0;
        for(int i = 0;i<a.length();i++){
            if(a[i] != b[i]){
                ans++;
            }
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<int>vis(n , -1);
        int index = 0;
        queue<string>q;
        int vf = 1;
        vector<string>vo;
        unordered_map<string , int>ma;
        for(int i = 0;i<n;i++){
            if(comp(beginWord , wordList[i]) == 1){
                ma[wordList[i]] = 2;
                q.push(wordList[i]);
            }
            else{
                vo.push_back(wordList[i]);
            }
            if(wordList[i] == endWord){
                vf = 2;
            }
        }
        if(vf == 1){
            return 0;
        }
        wordList = vo;
        vo.clear();
        while(!q.empty()){
            string f = q.front();
            q.pop();
            for(int i = 0;i<wordList.size();i++){
                if(comp(f,wordList[i]) == 1){
                    if(!ma[wordList[i]])
                    {
                        ma[wordList[i]] = ma[f] + 1;
                        q.push(wordList[i]);
                    }
                    else if(ma[wordList[i]] >= ma[f] + 1){
                        ma[wordList[i]] = ma[f] + 1;
                        q.push(wordList[i]);
                    }
                }
                else{
                    vo.push_back(wordList[i]);
                }
            }
            wordList = vo;
            vo.clear();
        }
        return ma[endWord];
    }
};