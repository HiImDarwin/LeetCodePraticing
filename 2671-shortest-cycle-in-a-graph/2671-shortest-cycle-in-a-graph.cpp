class Solution {
   int n;
   vector<unordered_set<int>> adj;
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) 
    {
      this->n = n;
      adj.resize(n);
      for (auto& edge: edges) {
        int a = edge[0], b = edge[1];
        adj[a].insert(b);
        adj[b].insert(a);
      }
      int res = INT_MAX;
      for (auto& edge: edges) {
        int a = edge[0], b = edge[1];
        adj[a].erase(b);
        adj[b].erase(a);
        res = min(res, bfs(a,b));
        adj[a].insert(b);
        adj[b].insert(a);
      }

      return res == INT_MAX ? -1 : res+1;
    }

    int bfs (int start, int end) {
      vector<int> visited(n);
      queue<int> q;
      q.push(start);
      visited[start] = 1;

      int step = 0;
      while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
          int cur = q.front();
          q.pop();
          if (cur == end) return step;
          for (int nxt: adj[cur]) {
            if (visited[nxt]) continue;
            q.push(nxt);
            visited[nxt] = 1;
          }
        }
        step++;
      }
      return INT_MAX;
    }
};

