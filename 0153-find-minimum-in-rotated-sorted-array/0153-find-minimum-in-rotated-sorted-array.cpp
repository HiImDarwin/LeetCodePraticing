class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]<nums[n-1]) return nums[0];
        int left =0;
        int right = n-1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[left]) left =mid;
            else right = mid;
        }
        return nums[(left+1)%n];
    }
};