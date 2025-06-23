class Solution {
  public:
    // int maximalSquare(vector<vector<char>>& matrix) {
    //   int m = matrix.size();
    //   int n = matrix[0].size(); 
    //   int max = 0;

    //   vector<vector<bool>> tmp(m, vector<bool>(n,0));
    //   vector<vector<bool>> tmp2(m, vector<bool>(n,0));
    //   for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //       tmp[i][j] = (matrix[i][j] == '1') ? true : false;
    //       if(tmp[i][j]) max = 1;
    //     }
    //   }

    //   bool foundLarger;
    //   for (int size = 2; size <= min(m, n); ++size) {
    //     foundLarger = false;
    //     for (int i = 0; i <= m - size; ++i) {
    //       for (int j = 0; j <= n - size; ++j) {
    //         tmp2[i][j] = tmp[i][j] && tmp[i+1][j] && tmp[i][j+1] && tmp[i+1][j+1];
    //         if(tmp2[i][j]) foundLarger = true;
    //       }
    //     }
    //     tmp = tmp2;
    //     if(foundLarger) max++;
    //     else break;
    //   }

    //   return max*max;
    // }
    int maximalSquare(vector<vector<char>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      int maxLen = 0;
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

      for (int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
          if(matrix[i-1][j-1] == '1') {
            dp[i][j] = min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) +1;
            maxLen = max(maxLen, dp[i][j]);
          }
        }
      }
      return maxLen*maxLen;
    }
};