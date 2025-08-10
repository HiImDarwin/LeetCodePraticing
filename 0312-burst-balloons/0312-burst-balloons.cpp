class Solution {
  public:
    int maxCoins(vector<int>& nums) {
      int n = nums.size();
      nums.insert(nums.begin(),1);
      nums.push_back(1);
      vector<vector<int>> dp(n+2,vector<int>(n+2,0));

      for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
          int j = i + len - 1;
          for (int k = i; k <= j; k++) {
            dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1] * nums[k] * nums[j+1]);
          }
        }
      }
      return dp[1][n];

    }
};

/*
 問題要你給 maximum coins you can collect by bursting the balloons
 這通常都是必須往DP想，因為你可能需要enumerate所有可能

 dp[i][j] = [i x x x x x x j]

 這時候思考射氣球最後一步 當我們剩一個氣球的時候 K
 [i x x x x x ] k [k+1 x x x x j] 左方value + 右方value + k

dp[i][j] = max {dp[i][k-1] + dp[k+1][j] +  nums[k] * nums[i-1]* nums[i+1]};
*/