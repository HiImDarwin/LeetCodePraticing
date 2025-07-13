class Solution {
  struct DSU {
    vector<int> parent,rank;
    DSU(int n) :parent(n), rank(n,0) {
      iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
      return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
      int px = find(x),py = find(y);
      if(px == py) return false;
      if(rank[px] < rank[py]) swap(px,py);
      parent[py] = px;
      return true;
    }
    
  };
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
      sort(edges.begin(),edges.end(),[](auto &a, auto &b) {
        return a[2] < b[2];
      });

      DSU dsu(n);
      vector<int> mstEdges;
      for(auto &e : edges) {
        if (dsu.unite(e[0],e[1])) {
          mstEdges.push_back(e[2]);
        }
      }

      sort(mstEdges.begin(),mstEdges.end());
      for (int i = 0; i < k-1 && !mstEdges.empty(); ++i) {
        mstEdges.pop_back();
      }
      return mstEdges.empty() ? 0 : mstEdges.back();
    }
};


/*
remove at least ? edge and left at most k node
component weight is the maximum edge weight it has


 minimum possible value of maximum cost



 first calculate how many component right now
 visited array + DFS
 union join with a weight

  1 --- 2 --- 3 --- 4
      2    10    5
*/