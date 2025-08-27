class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int n = nums.size();
      int left = 1, right = n;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (countElement(nums, mid) > mid) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }

    int countElement(vector<int>& nums , int target) {
      int count = 0;
      for (const auto& num : nums) {
        if (num <= target) {
          count++;
        }
      }
      return count;
    }
};


/*
binarySearch + counting


index Sorting



*/