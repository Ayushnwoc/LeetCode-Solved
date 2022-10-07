class Solution {
public:
    int maxProfit(vector<int>& values) {
        int n = values.size();
        long long int profit = 0;
        long long int buy = values[0];
        for(int i =1;i<n;i++){
            if(buy > values[i]){
                buy = values[i];
            }
            else if (buy < values[i]){
                profit += values[i] - buy;
                buy = values[i];
            }
        }
        return profit;
    }
};