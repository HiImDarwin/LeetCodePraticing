class Solution 
{
  public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
      int n = matrix.size();
      vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
      dp[0] = matrix[0];
      for(int i = 1; i < n; ++i) {
        for(int j = 0; j < n; j++) {
          dp[i][j] = dp[i-1][j] + matrix[i][j];
          if (j - 1 >= 0) {
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + matrix[i][j]);
          }
          if (j + 1 < n) {
            dp[i][j] = min(dp[i][j], dp[i-1][j+1] + matrix[i][j]);
          }
        }
      }
      int res = INT_MAX;
      for(int i = 0; i < n; i++) {
        res = min(res, dp[n-1][i]);
      }
      return res;
    }
};