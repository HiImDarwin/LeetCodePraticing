class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      m_ = matrix.size();
      n_ = matrix[0].size();
      memo_.resize(m_, vector<int>(n_, -1));

      int res = 0;
      for (int i = 0; i < m_; i++) {
        for (int j = 0; j < n_; j++) {
          if (memo_[i][j] == -1) {
            res = max(res, dfs(matrix, i, j));
          } 
        }
      }
      return res;
        
    }
  private:
    int dfs(vector<vector<int>>& matrix, int x, int y) {
      if (memo_[x][y] != -1) {
        return memo_[x][y];
      }
      int maxLen = 0; 
      for (auto [dx, dy] : directions) {
        int nei_x = x + dx;
        int nei_y = y + dy;
        if (nei_x < 0 || nei_x >= m_ || nei_y < 0 || nei_y >= n_ || 
            matrix[nei_x][nei_y] <= matrix[x][y]) {
          continue;
        }
        maxLen = max(maxLen, dfs(matrix, nei_x, nei_y));
      }
      return memo_[x][y] = maxLen + 1;
    }
    vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m_;
    int n_;
    vector<vector<int>> memo_;
};


/*
  dfs

*/