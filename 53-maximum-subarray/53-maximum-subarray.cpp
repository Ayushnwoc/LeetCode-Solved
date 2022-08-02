class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi= nums[0];
        for(int i = 0;i<nums.size(); i++)
        {
            sum += nums[i];
            if(sum<=0)
            {
                sum = 0;
                maxi = max(maxi,nums[i]);
            }
            else
            {
                maxi = max(maxi,sum);
            }
        } 
        return maxi;
    }
};


























// int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int maxi= nums[0];
//         for(int i = 0;i<nums.size(); i++)
//         {
//             sum += nums[i];
//             if(sum<=0)
//             {
//                 sum = 0;
//                 maxi = max(maxi,nums[i]);
//             }
//             else
//             {
//                 maxi = max(maxi,sum);
//             }
//         } 
//         return maxi;
//         }