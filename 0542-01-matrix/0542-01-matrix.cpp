class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m = mat.size(), n = mat[0].size();
      vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
      queue<pair<int,int>> qu;
      for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
          if(mat[i][j] == 0) {
            dist[i][j] = 0;
            qu.push({i,j});
          }
        }
      }

      while (!qu.empty()) {
        auto [x,y] = qu.front(); qu.pop();
        for(auto [dx,dy] : directions) {
          int neiX = x + dx, neiY = y + dy;
          if(neiX < 0 || neiX >= m || neiY < 0 || neiY >= n || dist[neiX][neiY]!=INT_MAX) continue;
          dist[neiX][neiY] = dist[x][y]+1;
          qu.push({neiX, neiY});
        }
      }
      
      return dist;
    }
  private:
    const vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
};