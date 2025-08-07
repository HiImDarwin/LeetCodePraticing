class Solution 
{
  public:
    int knightDialer(int n) 
    {
      vector<vector<int>> dp(n, vector<int>(12,0));
      int MOD = 1e9 + 7;

      for (int i = 0; i < 12; i ++) {
        if (i == 9 || i == 11) continue;
        dp[0][i] = 1;
      }

      for (int step = 1; step < n; step++) {
        for (int j = 0; j < 12; j++) {
          if (j == 9 || j == 11) continue;
          for(auto neighbor : neighborTable[j]) {
              dp[step][j] += dp[step-1][neighbor];
              dp[step][j] %= MOD;
          }
        }
      }
      int res = 0;
      for (int i = 0; i < 12; i++) {
        if (i == 9 || i == 11) continue;
        res += dp[n-1][i];
        res %= MOD;
      }
      return res;
    }

    vector<vector<int>> neighborTable = {
      {7,5},    // 0
      {6,8},    // 1
      {3,7},    // 2
      {2,8,10},  // 3
      {},       // 4
      {0,6,10},  // 5
      {1,5},    // 6
      {0,2},    // 7
      {1,3},    // 8
      {},
      {3,5},
      {}
    };
};


/*

dp[i][j] += dp[i_next][j-1]
*/