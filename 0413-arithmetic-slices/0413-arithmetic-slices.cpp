class Solution {
  public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();
      if(n < 3) return 0;
      int res = 0;
      int delta = nums[1] - nums[0];
      int startIdx = 0;
      for(int i = 1; i < n; ++i) {
        if(nums[i] - nums[i-1] != delta) {
          res += countSubArrayNum(startIdx, i-1);
          startIdx = i-1;
          delta = nums[i] - nums[i-1];
        }
      }
      res += countSubArrayNum(startIdx, n-1);
      return res;
    }
  
  int countSubArrayNum(int start, int end) {
    if ((end-start-1) < 1) return 0;
    return (end-start)*(end-start-1)/2;
  }
};