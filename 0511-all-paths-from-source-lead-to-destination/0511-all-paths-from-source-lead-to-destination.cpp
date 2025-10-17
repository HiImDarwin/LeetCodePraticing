class Solution {
  public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>> adj(n);
      for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
      }

      if (adj[destination].size() > 0) {
        return false;
      }
      vector<bool> visited(n, false);
      vector<int> memo(n, -1);
      return dfs(adj, visited, memo, source, destination);
    }
  private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited,
             vector<int>& memo, int source, int destination) {
      if (visited[source]) {
        return false;
      }
      if (memo[source] == 1) {
        return true;
      } 
      if (adj[source].size() == 0 && source != destination) {
        return false;
      }
      visited[source] = true;

      for (auto& nei : adj[source]) {
        if (!dfs(adj, visited, memo, nei, destination)) {
          return false;
        }
      }
      visited[source] = false;
      memo[source] = 1;
      return true;
    }
};
/*
  directed graph
  there migh be cycle in graph

  Return true if and only if all roads from source lead to destination.
    * can't have cycle int the path > infinite num of path

  DFS 
  * end with node destination or outdegree = 0
  * used a visited vector to avoid revisit

*/