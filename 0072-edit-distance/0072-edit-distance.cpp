class Solution {
public:
    int minDistance(string word1, string word2) {
      // longest subsequence
      int m = word1.length();
      int n = word2.length();
      vector<vector<int>> dp(m+1,vector<int>(n+1,0));
      for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
          if(i == 0 || j == 0) {
            dp[i][j] = i + j;
          } else if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          } else {
            dp[i][j] = 1+ min({dp[i - 1][j - 1],    // i 配對 j 修改值的情況
                               dp[i][j - 1],        // 前一個char 跟 j 配對 把自己刪除的情況
                               dp[i - 1][j]     }); // 自己配對 j-1 然後把 j 刪除的情況
          }

        }
      }
      return dp[m][n];
    }
};