class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int>height(n, 0);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1'){
                    height[j] = 1+height[j];
                }
                else{
                    height[j] = 0;
                }
                //cout<<height[j]<<" ";
            }
            int temp = lrih(height);
            //cout<<temp<<endl;
            ans = max(ans , temp);
        }
        return ans;
    }
    int lrih(vector<int>& vect) {
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