class Solution {
  int max_len = 0;
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    } else if (n == 0) {
      return {};
    }
    vector<vector<int>> adj(n);
    vector<int> path;
    for (auto& vec: edges) {
      int x = vec[0];
      int y = vec[1];
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    pair<int, int> a= find_longest_node(0, adj, -1);
    pair<int, int> b = find_longest_node(a.second, adj, -1);
    find_path(a.second, b.second, adj, path, -1);
    vector<int> res;
    res.push_back(path[path.size()/2]);
    if (path.size() % 2 == 0) {
      res.push_back(path[(path.size() - 1)/2]);
    }

    return res;
        
  }
  pair<int,int> find_longest_node(int node, vector<vector<int>>& adj, int par) {
    int path_length = 0;
    int longest_child = node;
    for (auto& chi : adj[node]) {
      if (chi == par) {
        continue;
      }
      pair<int,int> path = find_longest_node(chi, adj, node);
      if (path.first > path_length) {
        path_length = path.first;
        longest_child = path.second; 
      }
    }
    return {path_length + 1, longest_child};
  }

  bool find_path(int node, int end, vector<vector<int>>& adj, vector<int>& path, int par) {
    if (node == end) {
      path.push_back(node);
      return true;
    } else if (adj[node].size() == 1 && par != -1) {
      return false;
    }

    for (auto& chi : adj[node]) {
      if (chi == par) {
        continue;
      }
      if (find_path(chi, end, adj, path, node)) {
        path.push_back(node);
        return true;
      }
    }
    return false;
  }
};