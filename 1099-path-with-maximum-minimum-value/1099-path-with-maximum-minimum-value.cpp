class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
      int m = grid.size();
      int n  = grid[0].size();
      int left = 0, right = INT_MAX;
      while (left < right) {
        int mid = right - (right - left) / 2;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        if (checkPath(grid, 0, 0, visited, mid)) {
          left = mid;
        } else {
          right = mid - 1;
        }
      }
      return left;
    }
    bool checkPath(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited , int minVal) {
      if (grid[x][y] < minVal || visited[x][y]) {
        return false;
      }
      if (x == grid.size() - 1 && y == grid[0].size() - 1) 
        return true;
      
      visited[x][y] = true;
      bool res = false;
      for (auto [dx, dy] : directions) {
        int neiX = x + dx;
        int neiY = y + dy;
        if (neiX < 0 || neiX >= grid.size() || 
            neiY < 0 || neiY >= grid[0].size()) {
          continue;
        }
        res |= checkPath(grid, neiX, neiY, visited, minVal);
        if (res) return true;
      }

      return res;
    }
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
};


/*

[OOO???] XXXXX


*/