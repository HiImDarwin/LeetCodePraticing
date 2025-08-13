class Solution {
  unordered_map<int,vector<int>> mapX;
  unordered_map<int,vector<int>> mapY;
  public:
    int removeStones(vector<vector<int>>& stones) {
      int n = stones.size();
      vector<int> group(n);
      iota(group.begin(),group.end(),0);
      for (int i = 0; i < n; i++) {
        int x = stones[i][0];
        int y = stones[i][1];
        mapX[x].push_back(i);
        mapY[y].push_back(i);
      }


      auto find = [&](auto&& self, int x) -> int {
        if (group[x] != x) {
          group[x] = self(self, group[x]);
        }
        return group[x];
      };

      auto unite = [&](int x, int y) -> void {
        int u = find(find,x);
        int v = find(find,y);
        if (u == v) return;
        if (u < v) {
          group[v] = u; 
        } else {
          group[u] = v;
        }
      };

      for (auto a : mapX) {
        int id0 = a.second[0];
        for (int i = 1; i < a.second.size(); i++) {
          unite(id0, a.second[i]);
        }
      }
      for (auto a : mapY) {
        int id0 = a.second[0];
        for (int i = 1; i< a.second.size(); i++) {
          unite(id0, a.second[i]);
        }
      }
      unordered_set<int> Set;
      for(int i = 0; i < n; i++) {
        Set.insert(find(find,i));
      }
      
      return n - Set.size();
    }
};


/*
  view the same row or colume stone as connected -> they are in same island
  so the maximum stone can be remove = stones num - island num
*/