class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      if(nums.size() == 0) return {-1,-1};
      vector<int> res(2,-1);
      res[0] = lowerBound(nums, target);
      res[1] = upperBound(nums, target);
      return res;
    }

    int lowerBound (vector<int>& nums, int target) {
      int left = 0, right = nums.size()-1;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
          left = mid + 1;
        } else {
          right  = mid;
        }
      }
      return nums[left] == target ? left : -1 ;
    }
    int upperBound (vector<int>& nums, int target) {
      int left = 0, right = nums.size()-1;
      while (left < right) {
        int mid = right - (right - left) / 2;
        if( nums[mid] > target ){
          right = mid-1;
        } else {
          left = mid;
        }
      }
      return nums[right] == target ? right : -1;
    }
};