class Solution {

public:
    // int findShortestCycle(int n, vector<vector<int>>& edges) 
    // {
    //   this->n = n;
    //   adj.resize(n);
    //   for (auto& edge: edges) {
    //     int a = edge[0], b = edge[1];
    //     adj[a].insert(b);
    //     adj[b].insert(a);
    //   }
    //   int res = INT_MAX;
    //   for (auto& edge: edges) {
    //     int a = edge[0], b = edge[1];
    //     adj[a].erase(b);
    //     adj[b].erase(a);
    //     res = min(res, bfs(a,b));
    //     adj[a].insert(b);
    //     adj[b].insert(a);
    //   }

    //   return res == INT_MAX ? -1 : res+1;
    // }

    // int bfs (int start, int end) {
    //   vector<int> visited(n);
    //   queue<int> q;
    //   q.push(start);
    //   visited[start] = 1;

    //   int step = 0;
    //   while (!q.empty()) {
    //     int len = q.size();
    //     for (int i = 0; i < len; ++i) {
    //       int cur = q.front();
    //       q.pop();
    //       if (cur == end) return step;
    //       for (int nxt: adj[cur]) {
    //         if (visited[nxt]) continue;
    //         q.push(nxt);
    //         visited[nxt] = 1;
    //       }
    //     }
    //     step++;
    //   }
    //   return INT_MAX;
    // }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
      this->n = n;
      adj.resize(n);
      for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].insert(v);
        adj[v].insert(u);
      }

      int res = INT_MAX;
      for (int i = 0; i < n; i++) {
        if (adj[i].size() >= 2) {
          
          bfs(i, res);
        }
      }

      return res == INT_MAX ? -1 : res;
    }

    void bfs(int start , int &res) {
      vector<int> dist(n, -1);
      queue<pair<int, int>> qu; // node parent
      qu.push({start,-1});
      dist[start] = 0;

      while (!qu.empty()) {
        auto [node, parent] = qu.front();
        qu.pop();

        for (const int &v : adj[node]) {
          if (dist[v] == -1) {
            qu.push({v, node});
            dist[v] = dist[node] + 1;
          } else if (v != parent) {
            res = min(res, dist[node] + dist[v] + 1);
          }
        }
      }
    }
  private:
    int n;
    vector<unordered_set<int>> adj;
};

/*

BFS
  find out the adj map for each node
  start with any node
  memo for step in each node
*/


 

