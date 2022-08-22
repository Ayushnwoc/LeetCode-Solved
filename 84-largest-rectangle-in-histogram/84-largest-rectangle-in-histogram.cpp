class Solution {
public:
    int largestRectangleArea(vector<int>& vect) {
        map<int,int>m;
        int n = vect.size();
        int ans = 0;
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>s;
        for(int i = 0;i<n;i++){
            while(!s.empty() && vect[i]<=vect[s.top()]){
                s.pop();
            }
            
            if(s.empty()){
                left[i] = 0;
            }
            else{    
                left[i] = s.top() + 1;
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && vect[i]<=vect[s.top()]){
                s.pop();
            }
            
            if(s.empty()){
                right[i] = n-1;
            }
            else{    
                right[i] = s.top() - 1;
            }
            s.push(i);
        }
        for(int i = 0;i<n;i++){
            ans = max(ans , vect[i]*(right[i] - left[i] + 1));
        }
        return ans;
    }
};