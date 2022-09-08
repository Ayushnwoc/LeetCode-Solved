class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2 , -1);
        int left = 0 ;
        int n = nums.size() ;int right = n - 1;
        int flag = -1;
        while(left <= right){
            int mid = left + (right - left)/2 ;
            if(nums[mid] == target){
                if(flag == -1){
                    flag = mid;
                }
                ans[0] = mid;
                right = mid - 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(ans[0] == -1){
            return ans;
        }
        right = n - 1;
        left = flag+1;
        while(left <= right){
            int mid = left + (right - left)/2 ;
            if(nums[mid] == target){
                ans[1] = mid;
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(ans[1] == -1){
            ans[1] = flag;
        }
        return ans;
    }
};