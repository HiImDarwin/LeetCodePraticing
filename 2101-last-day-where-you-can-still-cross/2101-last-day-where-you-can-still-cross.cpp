class DSU {
  public:
  
    DSU(int n) {
      root_.resize(n);
      iota(root_.begin(), root_.end(), 0);
      size_.resize(n,1);
    }

    int find(int x) {
      if (root_[x] != x) {
        root_[x] = find(root_[x]);
      }
      return root_[x];
    }

    bool unite(int x, int y) {
      int rootX = find(x);
      int rootY = find(y);
      if (rootX == rootY) {
          return false;;
      }
      
      if (size_[rootX] > size_[rootY]) {
        swap(rootX, rootY);
      }
      root_[rootX] = rootY;
      size_[rootY] += size_[rootX];

      return true;
    }
  
  private:
    vector<int> root_;
    vector<int> size_;
};

class Solution {
  public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
      DSU dsu = DSU(row * col + 2);// last 2 is top and bot
      vector<vector<int>> grid(row,vector<int>(col,1));

      for (int i = cells.size() - 1; i >= 0; i--) {
        int x = cells[i][0] - 1, y = cells[i][1] - 1;
        int index = x * col + y;
        grid[x][y] = 0;

        for (auto& [dx, dy] : directions) {
          int nei_x = x + dx;
          int nei_y = y + dy;
          if (nei_x < 0 || nei_x >= row || nei_y < 0 || nei_y >= col || grid[nei_x][nei_y] == 1) {
            continue;
          }
          int nei_index = nei_x * col + nei_y;
          dsu.unite(index, nei_index);
        }
        if (x == 0) {
          dsu.unite(index, row * col);
        }
        if (x == row - 1) {
          dsu.unite(index, row * col + 1);
        }
        if (dsu.find(row * col) == dsu.find(row * col + 1)) {
          return i;
        }
      }
      return -1;
    }
  private:
    vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};



/*
Return the last day where it is possible to walk from the top to the bottom by only walking on land cells
binary Search + bfs


backwarding union find

*/

