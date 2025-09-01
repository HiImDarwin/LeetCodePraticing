class Solution 
{
  public:
    // int countSquares(vector<vector<int>>& matrix) 
    // {
    //   int m = matrix.size();
    //   int n = matrix[0].size();
    //   vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    //   for (int i = 1; i <= m; ++i) {
    //     for (int j = 1; j <=n; j++) {
    //       dp[i][j] = matrix[i-1][j-1];
    //     }
    //   }
    //   int res = 0;

    //   for (int i = 1; i <= m; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //       if(dp[i][j] == 0) {
    //         continue;
    //       }

    //       dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
    //       res += dp[i][j];
    //     }
    //   }
    //   return res;
    // }
    int countSquares(vector<vector<int>>& matrix) {
      int res = 0;
      int m = matrix.size();
      int n = matrix[0].size();

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (i == 0 || j == 0) {
            res += matrix[i][j];
          } else if (matrix[i][j] == 1) {
            matrix[i][j] = min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]}) + 1;
            res += matrix[i][j];
          }
        }
      }

      return res;
    }
};

/*

  brute force
  for each n 
  we can check from width 1 ~ i

  [1,1,1,1]
  [1,1,1,1]
  [0,1,1,1]
  
  in the brute force way their will have many duplicate check
  try to memerize the  check we have done 

  dp[i][j] : maximum square for useing [i][j] as right bot corner 
  dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]);

*/