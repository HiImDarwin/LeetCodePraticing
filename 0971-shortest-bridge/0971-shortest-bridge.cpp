class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
      int n = grid.size();
      queue<pair<int,int>> qu;
      vector<vector<bool>> visited(n, vector<bool>(n, false));
      

      bool findOne= false;
      for(int i = 0; i<n && !findOne; ++i) {
        for(int j = 0; j<n && !findOne; ++j) {
          if(grid[i][j] == 1 && !findOne) {
            dfs(grid, visited, qu, i, j);
            findOne = true;
          }
        }
      }

      int steps = 1;
      while(!qu.empty()) {
        int size = qu.size();
        while(size--) {
          auto [x,y] = qu.front(); qu.pop();
          for(auto [dx,dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
                continue;
            if(grid[nx][ny] == 1) return steps;
            visited[nx][ny] = true;
            qu.push({nx,ny});
          }
        }
        steps++;
      }
      return -1;
    }

  void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
             queue<pair<int,int>>& qu, int x, int y) {
        int n = grid.size();
        if(x < 0 || y < 0 || x >= n || y >= n || visited[x][y] )
            return;
        if(grid[x][y] == 0) {
          qu.push({x,y});
          visited[x][y] = true;
          return;
        }
        
        visited[x][y] = true;
        for(auto [dx,dy] : directions) {
            dfs(grid, visited, qu, x + dx, y + dy);
        }
  }
    const vector<pair<int,int>> directions {{1,0},{-1,0},{0,1},{0,-1}};
};