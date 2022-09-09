class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int time = 0;
        int z = 0;
        for(int i =0 ;i<= s.length() - 1 ;i++){
            z += s[i] == '0';
            if(z && s[i]=='1'){
                time = max(time + 1 , z);   
            }
        }
        return time;
    }
};