using ll = long long;
class Solution 
{
  private:
    int mod = 1e9 + 7;
    vector<int> dp;
    int go (int u, vector<int>& dist, vector<vector<pair<int,int>>>& adj) 
    {
      if (u == dist.size() - 1) return 1;
      if (dp[u] != -1) return dp[u];
      ll ans = 0;
      for(auto [v, w] : adj[u]) {
        if (dist[u] > dist[v]) {
          ans += go(v, dist, adj);
          ans %= mod;
        }
      }
      return dp[u] = ans;
    }
  public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
      vector<vector<pair<int, int>>> adj(n+1);
      for(auto edge : edges) {
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
      }

      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
      vector<int> dist(n+1, INT_MAX);
      dist[n] = 0;
      pq.push({0,n});
      while (!pq.empty()) {
        auto [distant, node] = pq.top();
        pq.pop();
        if (distant > dist[node]) {
          continue;
        }
        for (auto [v, w] : adj[node]) {
          if (dist[v] > dist[node] + w) {
            dist[v] = dist[node] + w;
            pq.push({dist[v],v});
          }
        }
      }
      dp.resize(n+1, -1);
      return go(1, dist, adj);
    }
};