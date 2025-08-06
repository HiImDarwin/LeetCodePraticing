class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      int MOD = 1e9+7;
      vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(2)));

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          dp[i][j][0] = INT_MIN;
          dp[i][j][1] = INT_MAX;
        }
      }
      if(grid[0][0] == 0) {
        return 0;
      } else if (grid[0][0] < 0){
        dp[0][0][1] = grid[0][0];
      } else {
        dp[0][0][0] = grid[0][0];
      }

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 0) {
              dp[i][j][0] = 0;
              dp[i][j][1] = 0;
          } else if(grid[i][j] > 0) {
            if (i - 1 >= 0) {
              dp[i][j][0] = (dp[i-1][j][0] == INT_MIN )? dp[i][j][0] : max(dp[i][j][0], dp[i-1][j][0] * grid[i][j]);
              dp[i][j][1] = (dp[i-1][j][1] == INT_MAX )? dp[i][j][1] : min(dp[i][j][1], dp[i-1][j][1] * grid[i][j]);
            }
            if (j - 1 >= 0) {
              dp[i][j][0] = (dp[i][j-1][0] == INT_MIN )? dp[i][j][0] : max(dp[i][j][0], dp[i][j - 1][0] * grid[i][j]);
              dp[i][j][1] = (dp[i][j-1][1] == INT_MAX )? dp[i][j][1] : min(dp[i][j][1], dp[i][j - 1][1] * grid[i][j]);
            }
          } else {
            if (i - 1 >= 0) {
              dp[i][j][0] = (dp[i-1][j][1] == INT_MAX )? dp[i][j][0] : max(dp[i][j][0], dp[i-1][j][1] * grid[i][j]);
              dp[i][j][1] = (dp[i-1][j][0] == INT_MIN )? dp[i][j][1] : min(dp[i][j][1], dp[i-1][j][0] * grid[i][j]);
            }
            if (j - 1 >= 0) {
              dp[i][j][0] = (dp[i][j - 1][1] == INT_MAX )? dp[i][j][0] : max(dp[i][j][0], dp[i][j - 1][1] * grid[i][j]);
              dp[i][j][1] = (dp[i][j - 1][0] == INT_MIN )? dp[i][j][1] : min(dp[i][j][1], dp[i][j - 1][0] * grid[i][j]);
            }

          }
        }
      }
      return dp[m-1][n-1][0] == INT_MIN ? -1 : dp[m-1][n-1][0]%MOD;
    }
};


/*
brute force O(n^3)


DP O(n^2)
state 
dp[i][j][k] means the maximum positive and minimum negative at position [i][j]
dp[i][j][1] = max(dp[i-1][j][1],) 

*/