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
      vector<int> arrive(n, INT_MAX);
      nodeQueue.push({0, 0});
      arrive[0] = 0;
      while (!nodeQueue.empty()) {
        auto [time, node] = nodeQueue.top();
        nodeQueue.pop();
        if(arrive[node] < time) continue;

        for(auto [nei, weight] : adj[node]) {
          if(time + weight < disappear[nei] && time + weight  < arrive[nei]) {
            arrive[nei] = time + weight;
            nodeQueue.push({arrive[nei], nei});
          }
        }
      }

      for(int &x : arrive) {
        if(x == INT_MAX) {
          x = -1;
        }
      }

      return arrive;
    }
};

/*
find shortest path to every node

*/