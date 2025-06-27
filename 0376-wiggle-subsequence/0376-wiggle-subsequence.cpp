class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> dp(2, vector<int>(n, 0));
      dp[0][0] = 1; // 0 是上升區間
      dp[1][0] = 1; // 1 是下降區間

      for (int i=1;i<n;++i) {
        if(nums[i]- nums[i-1] > 0) {
          dp[0][i] = dp[1][i-1] + 1;
          dp[1][i] = dp[1][i-1];
        } else if(nums[i]- nums[i-1] < 0) {
          dp[0][i] = dp[0][i-1];
          dp[1][i] = dp[0][i-1]+1;
        } else {
          dp[0][i] = dp[0][i-1];
          dp[1][i] = dp[1][i-1];
        }
      }


      return max(dp[0][n-1], dp[1][n-1]);
        
    }
};