class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int c = 0;
        int ans = neededTime[c];
        int mini = ans;
        for(int i = 1;i<n;i++){
            if(colors[i] == colors[c]){
                mini = max(mini , neededTime[i]);
                ans += neededTime[i];
            }
            else{
                ans -= mini;
                c = i;
                mini = neededTime[i];
                ans += neededTime[i];
            }
        }
        return ans - mini;
    }
};