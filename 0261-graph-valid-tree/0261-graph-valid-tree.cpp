class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      if (n == 0) return true;
      vector<bool> visited(n, false);
      vector<vector<int>> adj(n);
      for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      if ( !dfs(0, -1, adj, visited)) {
        return false;
      }
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          return false;
        }
      }
      return true;
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj,
             vector<bool>& visited) {
      visited[node] = true;
      bool res = true;
      for (int child : adj[node]) {
        if (child == parent) {
          continue;
        }
        if (visited[child]) {
          return false;
        }
        res &= dfs(child, node, adj, visited);
      }
      return res;
    }
};