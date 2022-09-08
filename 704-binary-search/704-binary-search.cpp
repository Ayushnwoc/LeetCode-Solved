class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 ,n;
        int right = n =  nums.size()-1;
        int mid = (left + right)/2;
        while(left <= right && left >= 0 && right >= 0 && left <= n && right <= n )
        {
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid]> target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = (left + right)/2;
        }
        return -1;
    }
};
