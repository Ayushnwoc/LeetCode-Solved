class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sizeofstring = words[0].length();
        map<string , int>ms;
        int n = words.size() ;
        for(int i = 0;i<n;i++)
        {
            ms[words[i]]++;
        }
        vector<int>ans;
        int q = s.length() - sizeofstring*n;
        if(q < 0)
        {
            return ans;
        }
        for(int i = 0 ; i<=s.length() - sizeofstring*n  ; i++)
        {
            //cout<<s.substr( i ,sizeofstring*n )<<endl;
            bool ayush = check(s.substr( i ,sizeofstring*n ) , ms , sizeofstring );
            //cout<<ayush<<endl;
            if(ayush)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool check(string s , map<string,int>ms , int n)
    {
        int i = 0;
        unordered_map<string , int>m;
        while(i<= s.length() - n)
        {
            //cout<<s.substr( i , n)<<endl;
            if(m[s.substr( i , n)] < ms[s.substr( i , n)])
            {
                m[s.substr( i , n)]++;
                i+=n;
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};