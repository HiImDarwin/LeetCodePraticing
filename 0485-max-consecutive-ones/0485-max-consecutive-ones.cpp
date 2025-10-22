class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int res = 0;
      int count = 0;
      for (auto& num : nums) {
        if (num == 0) {
          res = max(res, count);
          count = 0;
        } else {
          count++;
        }
      }
      res = max(res, count);
      return res;
    }
};