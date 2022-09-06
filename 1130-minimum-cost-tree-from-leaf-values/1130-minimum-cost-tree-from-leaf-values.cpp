class Solution {
public:
    //matrix chain eliminate neighbours and combine
    int mctFromLeafValues(vector<int>& arr){
        int n = arr.size();
        int sum = 0;
        vector<int> st = {INT_MAX};
        for(int i = 0;i<n;i++){
            while( st.back() <= arr[i] ){
                int small = st.back();
                st.pop_back();
                sum += small*min(st.back(), arr[i]);
            }
            st.push_back(arr[i]);
        }
        for(int i = st.size()-1; i >= 2; --i){
            sum += st[i] * st[i-1];
        }
        return sum;
    }
};