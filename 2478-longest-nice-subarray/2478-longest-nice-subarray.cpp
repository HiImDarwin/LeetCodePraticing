class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
      int preAnd = 0;
      int res = 0;
      for (int i = 0, j = 0; i < nums.size(); i++) {
        while(nums[i] & preAnd) {
          preAnd ^= nums[j];
          j++;
        }
        
        res = max(res, i - j + 1);
        preAnd |= nums[i];
      }

      return res;  
    }
};