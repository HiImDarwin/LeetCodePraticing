class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
      m = grid.size();
      n = grid[0].size();
      visited.resize(m, vector<bool>(n, false));
      
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (!visited[i][j]) {
            if (dfs(grid, i, j, -1, -1, grid[i][j])) {
                return true;
            }
          }
        }
      }
      return false;
    }

    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py, char c) {
      visited[x][y] = true;
      for (auto& [dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx == px && ny == py) {
          continue;
        }
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          if (visited[nx][ny] && grid[nx][ny] == c) {
            return true;
          }
          if (grid[nx][ny] == c && dfs(grid, nx, ny, x, y, c)) {
            return true;
          }
        }
      }
      return false;
    }

    int m;
    int n;
    vector<vector<bool>> visited;
    vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

};

/*
dfs with two color
when we visit a node we turn it's value into '#' 
  if we meet a node with '# detect cycle
  when we backward we change the '#' to 'A' that's means this block have been visited

*/