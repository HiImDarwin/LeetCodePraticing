class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
      vector<vector<pair<int,int>>> adj(n);
      // O(E)
      for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int time = edge[2];
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});
      }
      vector<int> dist(n, INT_MAX);
      dist[0] = 0;
      
      //(E log E)
      priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
      pq.push({0,0});

      while (!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();
        if (time > dist[node]) {
          continue;
        }

        for (auto [nei, costTime] : adj[node]) {
          int arriveTime = time + costTime;
          if (arriveTime >= disappear[nei] || arriveTime >= dist[nei]) {
            continue;
          }
          dist[nei] = arriveTime;
          pq.push({arriveTime, nei});
        }
      }

      for (int& num : dist) {
        if (num == INT_MAX) {
          num = -1;
        }
      }
      return dist;
    }
};


/*
  time to reach every node
  bellman ford

*/