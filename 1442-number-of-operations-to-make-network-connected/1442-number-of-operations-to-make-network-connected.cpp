class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      int m = connections.size();
      if (m < n - 1) return -1;
      vector<int> group(n);
      iota(group.begin(),group.end(),0);

      auto find = [&](auto&& self, int x) -> int {
        if (group[x] != x) {
          group[x] = self(self, group[x]);
        }
        return group[x];
      };

      auto unite = [&](int x, int y) -> void {
        int u = find(find, x);
        int v = find(find, y);
        if (u == v) return;
        if (u < v) {
          group[v] = u;
        } else {
          group[u] = v;
        }
      };

      for (auto edge : connections) {
        int u = edge[0];
        int v = edge[1];
        unite(u,v);
      }
      unordered_set<int> Set;
      for (int i = 0; i < n; i++) {
        Set.insert(find(find, i));
      }
      return Set.size() - 1;
    }
};


/*

DFS

Disjoint Set


*/