class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
      for (int i = 0; i < grid.size(); i++) {
        if (grid[i][0] == 0) {
          flip(grid[i]);
        }
      }
      int res = 0;
      for (int col = 0; col < grid[0].size(); col++) {
        int zero = 0, one = 0;
        for (int row = 0; row < grid.size(); row++) {
          if (grid[row][col] == 1) {
            one++;
          } else {
            zero++;
          }
        }
        res += max(one, zero) * (1 << grid[0].size() - 1 - col);
      }
      return res;
    }
private:
  void flip (vector<int>& row) {
    for (int i = 0; i < row.size(); i++) {
      row[i] ^= 1;
    }
  }


};

/*
for row if grid[row][0] = 1 flip
for col if (0) more than  1 flip



*/