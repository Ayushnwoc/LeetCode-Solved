class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> a;
        int maxi = 0,count = 0;
        for(int i =1;i<=s.length();i++)
        {
            if(a[s[i-1]] == 0)
            {
                a[s[i-1]] = i;
                count++;
                if(count>maxi)
                {
                    maxi = count;
                }
            }
            else
            {
                i = a[s[i-1]] ;
                a.clear();
                count = 0;
            }
        }
        return maxi;
    }
};