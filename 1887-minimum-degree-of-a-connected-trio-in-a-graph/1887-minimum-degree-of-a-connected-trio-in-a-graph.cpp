class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
      vector<vector<int>> connect(n+1, vector<int>(n+1,0));
      vector<int> degree(n+1,0);
      vector<vector<int>> next(n+1);
      for(auto e : edges) {
        int u = e[0], v = e[1];
        connect[u][v] = 1;
        connect[v][u] = 1;
        degree[u]++;
        degree[v]++;
        
        if(u > v) swap(u,v);
        next[u].push_back(v);
      }
      int res = INT_MAX;
      for(int a = 1; a <=n; ++a) {
        for (int i = 0; i < next[a].size(); ++i) {
          for (int j = i+1; j < next[a].size(); ++j) {
            int b = next[a][i], c = next[a][j];
            if(connect[b][c] == 1) {
              res = min(res, degree[a] + degree[b] + degree[c] - 6);
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