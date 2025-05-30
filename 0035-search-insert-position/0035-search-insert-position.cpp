class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if(start > end) {
            return start;
        }
        int mid = (start+end)/2;
        int res = -1;
        if(nums[mid]==target) {
            res = mid;
        } else if (nums[mid]>target) {
            res = binarySearch(nums, start, mid-1, target);
        } else {
            res = binarySearch(nums, mid+1, end, target);
        }
        return res;
    }
};