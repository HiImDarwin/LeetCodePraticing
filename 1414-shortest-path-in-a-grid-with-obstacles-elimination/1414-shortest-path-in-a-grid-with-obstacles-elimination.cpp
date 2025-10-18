class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<vector<int>>> states(k + 1, vector<vector<int>>(m, vector<int>(n,INT_MAX)));
      for (int i = 0; i <=k; i++) {
        states[i][0][0] = 0;
      }
      queue<vector<int>> qu;
      qu.push({0, 0, k, 0});
      while (!qu.empty()) {
        vector<int> state = qu.front();
        qu.pop();
        int x = state[0];
        int y = state[1];
        int k_left = state[2];
        int step = state[3];
        if (x == m - 1 && y == n - 1) {
          return step;
        }
        for (auto [dx, dy] : directions) {
          int nei_x = x + dx;
          int nei_y = y + dy;
          int newSetp = step + 1;
          if (nei_x < 0 || nei_x >= m || nei_y < 0 || nei_y >= n) {
            continue;
          }
          if (grid[nei_x][nei_y] == 1) {
            int new_k_left = k_left - 1;
            if (new_k_left < 0 || newSetp >= states[new_k_left][nei_x][nei_y]) {
              continue;
            }
            states[new_k_left][nei_x][nei_y] = newSetp;
            qu.push({nei_x, nei_y, new_k_left, newSetp});
          } else {
            if (newSetp >= states[k_left][nei_x][nei_y]) {
              continue;
            }
            states[k_left][nei_x][nei_y] = newSetp;
            qu.push({nei_x, nei_y, k_left, newSetp});
          }
        }
      } 
      return -1;
    }


    vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};