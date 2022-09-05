class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        unordered_map<char,int>m;
        vector<int>v(26 , 0);
        for(int i = 0;i<n;i++){
            m[s[i]]++;
        }
        stack<char>st;
        string ans;
        for(int i = 0;i<n;i++){
            if(v[s[i] - 'a'] == 1){
                m[s[i]]--;
                continue;
            }
            while(!st.empty() && s[i] < st.top() && m[st.top()] > 1){
                m[st.top()]--;
                v[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            v[s[i] - 'a'] = 1;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};