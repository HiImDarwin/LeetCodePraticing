class Solution {
public:
    //brute force
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,INT_MAX));
      for (int i = 0; i <= m - k; i++) {
        for (int j = 0; j <= n - k; j++) {
          vector<int> tmp;
          for (int r = i; r < i+k; r++) {
            for (int c= j; c < j+k; c++) {
              tmp.push_back(grid[r][c]);
            }
          }
          sort(tmp.begin(), tmp.end());
          int diff = INT_MAX;
          for (int x = 1; x < tmp.size(); x++) {
            if (tmp[x] != tmp[x-1]) {
              diff = min(diff, abs(tmp[x] - tmp[x-1]));
            }
          }
          ans[i][j] = (diff== INT_MAX) ? 0 : diff;
        }
      }
      return ans;
    }
};

/*
  k  <= min(m,n)

  預先處理 k - 1 * k - 1 的比較結果 

  [* * *]
  [* * *]
  [* * *]
  dp[k][i][j] = dp[k-1][i][j] 
  
    
*/


