class Solution {
public:
    bool isScramble(string s, string t) {
        string temp = s+ '/' + t;
        if(m[temp] == 10)
        {
            return 0;
        }
        else if(m[temp] == 11)
        {
            return 1;
        }
        if(s == t )
        {
            return true;
        }
        int n = s.length();
        vector<int>v(26 , 0);
        for(int i = 0;i<n;i++)
        {
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(int i = 0;i<26;i++)
        {
            if(v[i] !=0)
            {
                m[temp] = 10;
                return false;
            }
        }
        
        for(int i = 1;i<n;i++)
        { 
            if( isScramble(s.substr(0,i), t.substr(0,i)) && isScramble(s.substr(i), t.substr(i))){
                m[temp] = 11;
                return true;
            }
            if( isScramble(s.substr(0,i), t.substr(n-i)) && isScramble(s.substr(i), t.substr(0,n-i)))
            {
                m[temp] = 11;
                return true;
            }
        }
        m[temp] = 10;
        return false;
    }
    map<string , int>m;
};