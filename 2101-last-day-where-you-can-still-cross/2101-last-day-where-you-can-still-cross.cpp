class Solution {
  vector<int> parent;
  int FindParent(int x) {
    if (parent[x] != x) {
      parent[x] = FindParent(parent[x]);
    }
    return parent[x];
  }

  bool Unite(int x, int y) {
    int xParent = FindParent(x);
    int yParent = FindParent(y);
    if (xParent == yParent) {
      return false;
    }
    if (xParent > yParent) {
      swap(xParent,yParent);
    }
    parent[yParent] = xParent;
    return true;
  }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
      parent.resize(row*col);
      iota(parent.begin(),parent.end(),0);
      vector<vector<int>> grid(row,vector<int>(col,0));
      for(auto& cell : cells) {
        int x = cell[0], y = cell[1];
        grid[x-1][y-1] = 1;
      }

      for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
          if (grid[i][j] == 1) {
            continue;
          }
          for (auto& [dx, dy] : directions) {
            int neiX = i + dx;
            int neiY = j + dy;
            if (neiX < 0 || neiX >= row || neiY < 0 || neiY >= col || grid[neiX][neiY] == 1) {
              continue;
            } 
            Unite(i * col + j, neiX * col + neiY);
          }
        }
      }

      int days = cells.size();
      while (days >=0 ) {
        for (int i = 0; i < col; ++i) {
          if (grid[0][i] == 1) continue;
          for (int j = 0; j < col; ++j) {
            if (grid[row-1][j] == 1) continue;
            int topParent = FindParent(i);
            int botParent = FindParent((row- 1) * col + j);
            if (topParent == botParent) return days;
          }
        }

        int recoverX = cells[days-1][0]-1;
        int recoverY = cells[days-1][1]-1;
        grid[recoverX][recoverY] = 0;
        for (auto& [dx, dy] : directions) {
          int neiX = recoverX + dx;
          int neiY = recoverY + dy;
          if (neiX < 0 || neiX >= row || neiY < 0 || neiY >= col || grid[neiX][neiY] == 1) {
            continue;
          } 
          Unite(recoverX * col + recoverY, neiX * col + neiY);
        }

        days--;
      }
      return -1;
    }

    vector<pair<int,int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};