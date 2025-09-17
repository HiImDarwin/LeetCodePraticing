class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
      int N = 100;
      vector<vector<double>> dp(N, vector<double>(N, 0));
      dp[0][0] = poured;
      for (int i = 1; i <= query_row; i++) {
        for (int j = 0; j <=  query_glass; j++) {
          dp[i][j] = (dp[i - 1][j] - 1 > 0) ? (dp[i - 1][j] - 1) / 2 : 0;
          if (j - 1 >= 0) {
            dp[i][j] += (dp[i - 1][j - 1] - 1 > 0) ? (dp[i - 1][j - 1] - 1) / 2 : 0;
          }
        }
      }

      return min(1.0,dp[query_row][query_glass]);
    }
};

/*
  we can find a a equation to the result


  DP[i][j] = (DP[i - 1][j] - 1) / 2 + (DP[i - 1][j + 1] - 1) / 2;   

*/