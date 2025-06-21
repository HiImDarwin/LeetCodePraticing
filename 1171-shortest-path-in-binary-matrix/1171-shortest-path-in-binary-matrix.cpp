class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n = grid.size();
      return BFS(grid);
    }

    int BFS(vector<vector<int>>& grid) {
      int n = grid.size();
      if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
      queue<pair<pair<int,int>,int>> qu;
      qu.push({{0,0},1});
      int count = 1;
      while(!qu.empty()) {
        pair<pair<int,int>,int>  tmp = qu.front(); qu.pop();
        int step = tmp.second;
        int xIdx = tmp.first.first, yIdx =  tmp.first.second;
        if(xIdx == n-1 && yIdx == n-1) return step;
        for (auto [x_var,y_var] : directrions) {
          int x = xIdx + x_var, y = yIdx + y_var;
          if(x < 0 || x == n || y < 0 || y == n) {
              continue;
            }
          if(grid[x][y] == 1) continue;
          grid[x][y] = 1;
          qu.push({{x,y},step+1});
        }
      }
      return -1;
    }

    vector<pair<int,int>> directrions = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
};