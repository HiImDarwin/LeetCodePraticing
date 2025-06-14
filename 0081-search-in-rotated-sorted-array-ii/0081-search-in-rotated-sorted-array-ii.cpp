class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size()-1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) {
                return true;
            }
            if( nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if(nums[mid] >= nums[left]) { //left side accending
                if(target < nums[mid] && nums[left] <= target) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else { //right side accending
                if(target > nums[mid] && target <=nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return false;
    }
};