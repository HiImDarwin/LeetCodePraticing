class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
      vector<int> degree(n+1,0);
      vector<unordered_set<int>> adj(n+1);
      for(auto e : edges) {
        int u = e[0], v = e[1];
        degree[u]++;
        degree[v]++;
        adj[u].insert(v);
        adj[v].insert(u);
      }
      int res = INT_MAX;
      for(int i = 0; i < n; ++i) {
        for (auto it1 = adj[i].begin(); it1 != adj[i].end(); ++it1) {
          for (auto it2 = next(it1); it2 != adj[i].end(); ++it2) {
            int u = *it1, v = *it2;
            if(adj[u].count(v)) {
              int total_deg = degree[i] + degree[u] + degree[v] - 6;
              res = min(res, total_deg);
          
            }
          }
        }
      }

      return res == INT_MAX ? -1 : res;
    }
};


/*
find trio set 
count degree of trio - 6



*/