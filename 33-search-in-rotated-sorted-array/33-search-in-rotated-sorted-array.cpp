class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 , n = nums.size() , right = n - 1;
        if(n == 1){
            if(nums[0] == target){
                return 0;
            }return -1;
        }
        int mid = fin(nums , n);
        if(nums[right] >= target){
            left = mid , right = n-1;
            while(left <= right){
                int i = (left + right)/2;
                if(nums[i] == target){
                    return i;
                }
                else if(nums[i] > target){
                    right = i - 1;
                }
                else{
                    left = i + 1;
                }
            }
            return -1;
        }
        else{
            left = 0 , right = mid - 1;
            while(left <= right){
                int i = (left + right)/2;
                if(nums[i] == target){
                    return i;
                }
                else if(nums[i] > target){
                    right = i - 1;
                }
                else{
                    left = i + 1;
                }
            }
            return -1;
        }
        return -1;
    }
    int fin(vector<int>&arr, int n) {
	    if(n == 1){
	        return 0;
	    }
	    int left = 0;
	    int right = n - 1;
	    int ans = 0;
	    while(left <= right){
	        int mid = left + (right - left)/2;
	        if(arr[mid] >= arr[0]){
	            left = mid + 1;
	        }
	        else{
	            ans = mid;
	            right = mid - 1;
	        }
	    }
	    return ans;
	}
    
};