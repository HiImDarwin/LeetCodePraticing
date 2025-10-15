class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      long long res = 0;
      int left = lower_bound(nums.begin(), nums.end(), lower - nums[0]) - nums.begin();
      int right = upper_bound(nums.begin(), nums.end(), upper - nums[0]) - nums.begin();

      if (left == 0) {
        left++;
      }
      res += right - left;

      for (int i = 1; i < n; i++) {
        left = max(i + 1, left);
        while (left - 1 > i  && nums[i] + nums[left - 1] >= lower) {
          left--;
        }
        while (right - 1 >= left && nums[i] + nums[right - 1] > upper) {
          right--;
        }
        if (left != n && left == i + 1 && nums[i] + nums[left] > upper) {
          break;
        }
        res += right - left;
      }

      return res;
    }
};

/*
sort + sliding window
for any interger i we want to find all j that can let
[x,x,x,x,x,x,x,x,x,x]
 ^       (       )


*/