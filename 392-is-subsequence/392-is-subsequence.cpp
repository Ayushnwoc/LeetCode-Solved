class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        int i = 0, j = 0;
        while(i<t.size())
        {
            if(t[i] == s[j])  
            {
                j++;
                cnt++;
            }
            i++;
        }
        if(cnt == s.length())
        {
            return true;
        }
        return false;
    }
};