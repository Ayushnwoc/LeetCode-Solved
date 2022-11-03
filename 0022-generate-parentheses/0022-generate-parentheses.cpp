class Solution {
public:
    vector<string> generateParenthesis(int n){
        string s = "" ;
        gen(s , n, n) ;
        return ans ;
    }
    void gen(string s ,int start , int end){
        if(start ==0 and end == 0){
            ans.push_back(s);
        }
        if(start){
            gen(s +'(' , start - 1 , end);
        }
        if(start < end){
            gen(s +')' , start , end-1);
        }
    }
    vector<string>ans;
};