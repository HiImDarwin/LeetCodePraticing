class Solution {
    int MOD = 1e9+7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k,0)));
      dp[0][0][grid[0][0]%k] = 1;
      for(int i = 0 ; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (i == 0 && j == 0) continue;
          for (int r = 0; r < k; r++) {
            int t = ((r - grid[i][j]) % k + k) % k;
            int left = j - 1 >= 0 ? dp[i][j-1][t] : 0;
            int up =  i - 1 >= 0 ? dp[i-1][j][t] : 0;
            dp[i][j][r] = (left + up) % MOD; 
          }
        }
      }
      return dp[m-1][n-1][0];
    }
};


/*

Time Complexity:


*/