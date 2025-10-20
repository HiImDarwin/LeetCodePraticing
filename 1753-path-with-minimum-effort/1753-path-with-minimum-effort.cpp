class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      int m = heights.size();
      int n = heights[0].size();
      root_.resize(m * n);
      iota(root_.begin(), root_.end(), 0);
      weight_.resize(m * n , 1);


      vector<array<int, 3>> edges; // {diff, u, v}
      for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 1 < m)
                    edges.push_back({abs(heights[i][j] - heights[i + 1][j]), i * n + j, (i + 1) * n + j});
                if (j + 1 < n)
                    edges.push_back({abs(heights[i][j] - heights[i][j + 1]), i * n + j, i * n + (j + 1)});
            }
        }
      sort(edges.begin(), edges.end());

      for (auto& [diff, u, v] : edges) {
            unite(u, v);
            if (find(0) == find(m * n - 1))
                return diff;
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