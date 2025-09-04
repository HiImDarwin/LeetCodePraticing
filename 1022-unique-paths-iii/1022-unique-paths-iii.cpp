class Solution {
  int m,n,emptyCount,res = 0;
  int startX, startY, endX, endY;
  vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
      m = grid.size();
      n = grid[0].size();
      emptyCount = 0;


      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            startX = i;
            startY = j;
          } else if (grid[i][j] == 2) {
            endX = i;
            endY = j;
          }
          if (grid[i][j] != -1) {
            emptyCount++;
          }
        }
      }
      dfs(grid, startX, startY, 1);
      return res;
    }

    void dfs(vector<vector<int>>& grid, int x , int y, int count) {
      if (x == endX && y == endY) {
        if (count == emptyCount) res++;
        return;
      }
      int tmp = grid[x][y];
      grid[x][y] = -1;
      for (auto& [dx, dy] : dir) {
        int newX = x + dx;
        int newY = y + dy;
        if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == -1) {
          continue;
        }
        dfs(grid, newX, newY, count + 1);
      }
      grid[x][y] = tmp;
    }
};