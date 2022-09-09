class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans ;
        int m = nums1.size() , n = nums2.size();
        if(n < m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int t = m + n;
        int left = 0 , right = m;
        while(left <= right){
            int mid = left + (right - left)/2;
            int temp = (t+1)/2 - mid;
            int left1 = mid == 0 ? INT_MIN : nums1[mid-1];
            int left2 = temp == 0 ? INT_MIN : nums2[temp-1];
            
            int right1 = mid == m ? INT_MAX : nums1[mid];
            int right2 = temp == n ? INT_MAX : nums2[temp];
            
            if(left1 <= right2 && right1 >= left2){
                if(t%2 == 0){
                    return (max(left1 , left2) + min(right1 , right2))/2.0;
                }
                else{
                    return max(left1 , left2)/1.0;
                }
            }
            else if(left1 > right2){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return 0.0;
    }
};