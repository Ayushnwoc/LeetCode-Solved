class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int time = 0;
        while(true){
            string temp;
            int count = 0;
            for(int i = 0;i<s.length();i++){
                if(i != 0 && s[i] == '1' && s[i-1] =='0'){
                    count++;
                    temp.pop_back();
                    temp += "10";
                }
                else{
                    temp += s[i];
                }
            }
            s = temp;
            if(count == 0){
                return time;
            }
            time++;
        }
    }
};