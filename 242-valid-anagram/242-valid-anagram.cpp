class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> sa;
        map<char,int> ta;
        for(int i =0;i<s.length();i++)
        {
            sa[s[i]] += 1;
        }
        for(int i =0;i<t.length();i++)
        {
            ta[t[i]] += 1;
        }
        if(sa == ta)
        {
            return true;
        }
        return false;
    }
};