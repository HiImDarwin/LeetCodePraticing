class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if(n == 1) return nums[0];
      int idxZero = findMax(nums, 0, n-2);
      int idxOne = findMax(nums, 1, n-1);
      return max(idxZero,idxOne);
      
    }
    int findMax(vector<int>& nums, int start, int end) {
      int prev1 = 0, prev2 = 0;
      for(int i = start; i <= end; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
      }
      return prev1;
    }
};



// dp[i] = max(dp[i-2]+ nums[i], dp[i-1]);