class Solution {
public:
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;
    //     if (n == 1) return nums[0];
    //     if (n == 2) return max(nums[0], nums[1]);
    //     vector<int> dp(n+1,0);
    //     dp[1] = nums[0];
    //     dp[2] = nums[1];
    //     for(int i = 3; i <= n; ++i) {
    //       dp[i] = max(dp[i-3],dp[i-2]) + nums[i-1];
    //     }
    //     return max(dp[n], dp[n-1]);
    // }
    int rob(vector<int>& nums) {
      int prev2 = 0, prev1 = 0;

      for(int i = 0; i<nums.size(); ++i) {
        int curr = max(prev1, prev2+nums[i]);
        prev2 = prev1;
        prev1 = curr;
      }  
      return prev1;
    }
};