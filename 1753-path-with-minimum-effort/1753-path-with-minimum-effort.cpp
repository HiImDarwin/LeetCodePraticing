class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      int m = heights.size();
      int n = heights[0].size();
      root_.resize(m * n);
      iota(root_.begin(), root_.end(), 0);
      weight_.resize(m * n , 1);


      map<int,vector<vector<int>>> mp;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (i + 1 < m) {
            int diff = abs(heights[i][j] - heights[i + 1][j]);
            mp[diff].push_back({i,j, i + 1, j});
          }
          if (j + 1 < n) {
            int diff = abs(heights[i][j] - heights[i][j + 1]);
            mp[diff].push_back({i,j, i, j + 1});
          }
        }
      }

      for (auto& [effort, setVec] : mp) {
        for (auto& set :setVec) {
          int x1 = set[0];
          int y1 = set[1];
          int x2 = set[2];
          int y2 = set[3];
          int idx1 = x1 * n + y1;
          int idx2 = x2 * n + y2;
          unite(idx1, idx2);
        }
        if (find(0) == find(m * n - 1)) {
          return effort;
        }
      }

      return 0;
    }
  private:
    vector<int> root_;
    vector<int> weight_;

    int find(int x) {
      if (root_[x] != x) {
        root_[x] = find(root_[x]);
      }
      return root_[x];
    }

    void unite(int x, int y) {
      int root_x = find(x);
      int root_y = find(y);
      if (root_x == root_y) {
        return;
      }
      if (weight_[root_x] < weight_[root_y]) {
        swap(root_x, root_y);
      }
      root_[root_y] = root_x;
      weight_[root_x] += weight_[root_y];
    }
};
/*
binary search + dfs

disjoint set

*/