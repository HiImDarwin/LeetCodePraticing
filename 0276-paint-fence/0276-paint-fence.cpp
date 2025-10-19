class Solution {
public:
    int numWays(int n, int k) {
      //[i][0] means. color same with previous
      // [i][1] means color different with previous
      vector<vector<int>> dp(n, vector<int>(2, 0)); 
      dp[0][0] = 0;
      dp[0][1] = k;
      for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) * (k - 1);
      }
      return dp[n - 1][0] + dp[n - 1][1];
    }
};

/*

dp[i][0]: i 與 i - 1 相同 
dp[i][0] = dp[i - 1][1]
dp[i][1]: i 與  i - 1 不同
dp[i][1] = dp[i - 1][0] * n - 1

*/