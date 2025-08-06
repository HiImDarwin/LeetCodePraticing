class Solution 
{
  private:
    int n;
    long long limitation;
  public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) 
    {
      n = online.size();
      limitation = k;
      vector<vector<pair<int,int>>> adj(n);
      
      vector<bool> visited(n,false);
      vector<vector<pair<int,int>>> memo(n); // sum & minPathCost
      memo[n-1].push_back({0,INT_MAX});
      int maxWeight = 0;
      for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        if (online[u] && online[v]) {
          adj[u].push_back({v,cost});
          maxWeight = max(maxWeight, cost);
        }
      }
      int left = -1, right = maxWeight;
      
      while (left < right) {
        int mid = right - (right - left) / 2;
        if (dijkstra(adj, mid)) {
          left = mid;
        } else {
          right = mid-1;
        }
      }
      return left;
    }

    bool dijkstra(vector<vector<pair<int,int>>>& adj, int miniWeight) 
    {
      priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
      vector<long long> dist(n,LLONG_MAX);
      dist[0] = 0;
      pq.push({0,0});
      while (!pq.empty()) {
        auto [currDist, node] =pq.top();
        pq.pop();
        if(currDist > dist[node]) continue;
        if (node == n-1) return true;
        for (auto [neighbor , cost] : adj[node]) {
          if (currDist + cost > limitation) continue;
          if (cost < miniWeight) continue;
          if (currDist + cost < dist[neighbor]) {
            dist[neighbor] = currDist + cost;
            pq.push({dist[neighbor], neighbor});
          }
        }
      }
      return false;
    }
};

/*
if we run dijkstra from 1 to n O(E log E)
limit the edge and 

O (n!) using dfs

*/