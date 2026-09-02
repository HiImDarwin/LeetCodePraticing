class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int islandCount = 0;
    for (int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          bfs(grid, i, j);
          islandCount++;
        }
      }
    }
    return islandCount;
  }

  void bfs(vector<vector<char>>& grid, int x, int y) {
    queue<pair<int,int>> qu;
    qu.push({x,y});
    grid[x][y] = '2';
    while(!qu.empty()) {
      auto [x, y] = qu.front();
      qu.pop();
      for (auto [dx, dy] : dir) {
        int neiX = x + dx;
        int neiY = y + dy;
        if (neiX < 0 || neiY < 0 || neiX >= grid.size() || 
            neiY >= grid[0].size() || grid[neiX][neiY] != '1') {
          continue;
        }
        grid[neiX][neiY] = '2';
        qu.push({neiX, neiY});
      }
    }
  }

  vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};