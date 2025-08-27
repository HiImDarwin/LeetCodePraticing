class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      long left = INT_MIN, right = INT_MAX;
      while (left < right) {
        int mid = right - (right - left) / 2;
        if (countElement(nums, mid) >= k) {
          left = mid;
        }  else {
          right = mid - 1;
        }
      }
      return left;
    }

    int countElement(vector<int>& nums, int mid) {
      int count = 0;
      for (auto& num : nums) {
        if (num >= mid) {
          count++;
        }
      }
      return count;
    }
};