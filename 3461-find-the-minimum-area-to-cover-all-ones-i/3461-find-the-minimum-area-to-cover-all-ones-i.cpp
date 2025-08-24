class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      int leftMost = INT_MAX;
      int rightMost = INT_MIN;
      int topMost = INT_MAX;
      int bottomMost = INT_MIN;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 0) continue;
          leftMost = min(leftMost, j);
          rightMost = max(rightMost, j);
          topMost = min(topMost,i);
          bottomMost = max(bottomMost,i);
        }
      }
      if (leftMost == INT_MAX) return 0;
      return( rightMost - leftMost + 1) * (bottomMost - topMost + 1);
    }
};