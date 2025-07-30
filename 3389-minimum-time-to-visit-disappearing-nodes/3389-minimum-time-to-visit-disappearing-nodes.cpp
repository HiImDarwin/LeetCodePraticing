class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
      vector<vector<pair<int,int>>> adj(n);

      for (auto e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
      }
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> nodeQueue;
      vector<int> visited(n,INT_MAX);
      vector<int> res(n, -1);
      nodeQueue.push({0,0});
      while (!nodeQueue.empty()) {
        auto [time, node] = nodeQueue.top();
        nodeQueue.pop();
        if(res[node] != -1 && res[node] < time) continue;
        res[node] = time;
        for(auto [nei, weight] : adj[node]) {
          if(time + weight < disappear[nei] && time + weight  < visited[nei]) {
            visited[nei] = time + weight;
            nodeQueue.push({visited[nei], nei});
          }
        }
      }
      return res;
    }
};

/*
find shortest path to every node

*/