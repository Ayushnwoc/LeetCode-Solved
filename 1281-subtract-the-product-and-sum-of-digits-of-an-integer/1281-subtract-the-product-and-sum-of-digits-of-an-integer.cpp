class Solution {
public:
    int subtractProductAndSum(int n) {
        string str = to_string(n);
        int p = 1,x;
        int s = 0;
        for(int i =0 ;i<str.length();i++)
        {
            x  = (str[i] - '0');
            p *= x;
            s += x;
        }
        return p-s;
    }
};