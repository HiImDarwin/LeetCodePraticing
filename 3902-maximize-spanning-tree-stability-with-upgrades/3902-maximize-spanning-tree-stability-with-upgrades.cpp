class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind  uf(n);
        int res = INT_MAX;
        auto cmp = [](const pair<int,vector<int>> &a, const pair<int,vector<int>> &b){
          return a.first < b.first;
        };
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,decltype(cmp)> pq;
        int edgeCount = n-1;
        for(auto edge : edges){
          if(edge[3] == 1){
            if(!uf.unite(edge[0],edge[1])) return -1;
            edgeCount--;
            res = min(res,edge[2]);
          } else {
            pq.push({edge[2],edge});
          }
        }

        while(edgeCount > 0 && !pq.empty()) {
          auto [weight,edge] = pq.top(); pq.pop();
          if(uf.unite(edge[0],edge[1])) {
            if(edgeCount > k) {
              res = min(res,weight);
            } else {
              res = min(res,weight*2);
            }
            edgeCount--;
          }
        }
        return edgeCount == 0 ? res : -1;
    }
  private:
    struct UnionFind {
      vector<int> parents;

      UnionFind(int n) :parents(n) {
        for (int i = 0; i < n; ++i) parents[i] = i;
      }

      bool unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if(rx == ry) return false;
        parents[ry] = rx;
        return true;
      }

      int find(int x) {
        return parents[x] == x ? x : parents[x] = find(parents[x]);
      }
    };
};

/*
k eligible edge will be upgrade
must have no cycle
MST method
  kurskal add minimum weight edge
  Prim
union find struct for check circle

*/