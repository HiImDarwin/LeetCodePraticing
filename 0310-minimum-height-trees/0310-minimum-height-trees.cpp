class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      if (edges.size() == 0 && n == 1) {
        return vector<int>{0};
      }
      vector<int> indegree(n,0);
      vector<vector<int>> adj(n);
      for (auto& edge : edges) {
        int a = edge[0];
        int b = edge[1];
        indegree[a]++;
        indegree[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
      }

      queue<int> qu;
      for (int i = 0; i < n; i++) {
        if (indegree[i] == 1) {
          qu.push(i);
        }
      }
      vector<int> res;
      while (!qu.empty()) {
        int m = qu.size();
        res.clear();
        for (int i = 0; i < m; i++) {
          int node = qu.front();
          qu.pop();
          res.push_back(node);

          for (int nei : adj[node]) {
            indegree[nei]--;
            if (indegree[nei] == 1) {
              qu.push(nei);
            }
          }
        }
      }

      return res;
    }
};
/*
  the minimum height tree root will be the  middle node in longest path 


  1. find the longest path int the tree
  2. backtracking the node on the path (longest path may not contain root)
  3. return the middle node of the path (if there are multi path they will have same middle node)
  

*/