class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int n = nums.size();
      int res = 0;
      int count1 = 0, count2 = 0;
      for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) {
          count2++;
        } else {
          res = max(res, count1 + count2);
          count1 = count2;
          count2 = 0;
          if (i > 0 && nums[i - 1] == 0) {
            count1 = 0;
          }
        }
      }
      res = max(res, count1 + count2);
      return res == nums.size() ? res - 1 : res;
    }
};