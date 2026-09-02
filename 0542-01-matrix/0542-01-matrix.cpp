class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<int,int>> qu;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          qu.push({i, j});
        } else {
          mat[i][j] = -1;
        }
      }
    }

    while (!qu.empty()) {
      auto [x, y] = qu.front();
      qu.pop();
      for (auto [dx, dy] : dir) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || mat[nx][ny] != -1) {
          continue;
        }
        mat[nx][ny] = mat[x][y] + 1;
        qu.push({nx, ny});
      }
    }
    return mat; 
  }

  vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};