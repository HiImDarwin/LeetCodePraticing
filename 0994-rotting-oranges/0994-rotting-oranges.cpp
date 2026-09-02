class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int,int>> qu;
    int fresh = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if (grid[i][j] == 2) { 
          qu.push({i, j});
        } else if (grid[i][j] == 1) {
          fresh++;
        }
      }
    }
    if (fresh == 0) {
      return 0;
    }
    int elapse = -1;
    while(!qu.empty()) {
      int sz = qu.size();
      elapse++;
      while(sz > 0) {
        auto [x, y] = qu.front();
        qu.pop();
        sz--;
        for (auto [dx, dy] : dir) {
          int neiX = x + dx;
          int neiY = y + dy;
          if (neiX < 0 || neiY < 0 || neiX >= m || neiY >= n || grid[neiX][neiY] != 1){
            continue;
          }
          grid[neiX][neiY] = 2;
          fresh--;
          qu.push({neiX, neiY});
        }
      }
    }

    return fresh == 0 ? elapse : -1;
  }


  vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};