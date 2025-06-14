class Solution {
public:
    // this way is find the pivot point
    // int findMin(vector<int>& nums) {
    //     int n = nums.size();
    //     int left =0;
    //     int right = n;
    //     while(left < right) {
    //         int mid = left + (right-left)/2;
    //         if(nums[mid] > nums[left]) left =mid;
    //         else right = mid;
    //     }
    //     return nums[(left+1)%n];
    // }
    int findMin(vector<int>& nums) {
        int right = nums.size()-1;
        int left = 0;
        while(left < right) {
            int mid = left+(right-left)/2;

            if(nums[mid]>nums[right]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};