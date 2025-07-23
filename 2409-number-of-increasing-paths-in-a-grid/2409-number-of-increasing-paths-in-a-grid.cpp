class Solution {
  const int MOD = 1e9+7;
  int m;
  int n;
  const vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int countPaths(vector<vector<int>>& grid) {
      m = grid.size();
      n = grid[0].size();
      vector<vector<int>> memo(m,vector<int>(n,-1));
      int res = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          res += dfs(i, j, grid, memo);
          res %=MOD;
        }
      }
      return res;
    }
    int dfs(int x,int y, vector<vector<int>>& grid,vector<vector<int>> &memo) {
      if(memo[x][y] != -1) return memo[x][y];
      int pathCount = 1;
      for(auto [dx, dy] : direction) {
        int neightborX = x + dx;
        int neightborY = y + dy;
        if (neightborX < m && neightborX >=0 && neightborY < n && 
            neightborY >=0 && grid[neightborX][neightborY] > grid[x][y]) {
          pathCount += dfs(neightborX, neightborY, grid, memo);
          pathCount %=MOD;
        }
      }
      memo[x][y] = pathCount;
      return pathCount;
    }
};