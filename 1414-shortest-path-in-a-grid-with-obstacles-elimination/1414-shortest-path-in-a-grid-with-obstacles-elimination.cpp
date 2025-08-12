class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dist(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
        queue<tuple<int,int,int>> qu;
        dist[0][0][k] = 0;
        qu.push({0,0,k});
        while (!qu.empty()) {
          auto [x, y, hammer] = qu.front();
          qu.pop();
          int step = dist[x][y][hammer];
          if (x == m-1 && y == n-1) return step;
          for (const auto& [dx, dy] : directions) {
            int nX = x + dx;
            int nY = y + dy;
            int newHammer = hammer;
            int newStep = step + 1;
            if (nX < 0 || nX >= m || nY < 0 || nY >= n) {
              continue;
            }
            if (grid[nX][nY] == 1) {
              if (newHammer <= 0) {
                continue;
              }
              newHammer--;
            } 
            if (newStep < dist[nX][nY][newHammer]) {
              dist[nX][nY][newHammer] = newStep;
              qu.push({nX, nY, newHammer});
            }
          }
        }
        return -1;
    }
    vector<pair<int,int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};
/*
  無法greedy 的說先用掉穿牆或是不用穿牆哪一個好。
  you need to record both satuation


*/