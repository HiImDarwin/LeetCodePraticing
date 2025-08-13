class Solution {
  public:
    int removeStones(vector<vector<int>>& stones) {
      int n = stones.size();
      vector<int> group(n);
      vector<int> weight(n,1);
      iota(group.begin(),group.end(),0);

      auto find = [&](auto&& self, int x) -> int {
        if (group[x] != x) {
          group[x] = self(self, group[x]);
        }
        return group[x];
      };

      auto unite = [&](int x, int y) -> bool {
        int u = find(find,x);
        int v = find(find,y);
        if (u == v) return false;
        if (weight[u] >= weight[v]) {
          group[v] = u;
          weight[u] += weight[v];
        } else {
          group[u] = group[v];
          weight[v] += weight[u];
        }
        return true;
      };
      int res = 0;
      for (int i = 0 ; i < n; i++) {
        for (int j = i+1; j < n; j++) {
          if (stones[i][0] == stones[j][0] ||stones[i][1] == stones[j][1]) {
            if (unite(i, j)) {
              res++;
            }
          }
        }
      }
      return res;
    }
};


/*
  X  XXXXX

      XX X
      X
      X
*/