class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
      int m = heightMap.size();
      int n = heightMap[0].size();

      vector<vector<bool>> visited(m,vector<bool>(n,false));
      using T = array<int, 3>; // {height, x, y}
      priority_queue<T, vector<T>, greater<>> pq;

      for (int i = 0; i < m; i++) {
        pq.push({heightMap[i][0], i, 0});
        pq.push({heightMap[i][n - 1], i, n - 1});
        visited[i][0] = true;
        visited[i][n - 1] = true;
      }

      for (int j = 0; j < n; j++) {
        pq.push({heightMap[0][j], 0, j});
        pq.push({heightMap[m - 1][j], m - 1, j});
        visited[0][j] = true;
        visited[m - 1][j] = true;
      }
      int res = 0;
      while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();
        for (auto& [dx, dy] : dirs) {
          int nx = x + dx;
          int ny = y + dy;
          if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
            continue;
          }
          visited[nx][ny] = true;
          int nh = heightMap[nx][ny];
          if (nh < height) {
            res += height - nh;
          }
          pq.push(array<int,3>{max(height, nh), nx, ny});
        }
      }

      return res;
    }
  private:
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};