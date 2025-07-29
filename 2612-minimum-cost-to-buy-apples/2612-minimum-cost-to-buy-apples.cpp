class Solution 
{
  public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) 
    {
      vector<vector<pair<int,long long>>> next(n+1);
      for (auto &road : roads) {
        int a = road[0], b = road[1], w = road[2];
        next[a].push_back({b, w});
        next[b].push_back({a, w});
      }

      vector<long long> res;

      for(int i = 1; i <= n; ++i) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0,i});
        //vector<bool> visited(n+1,false);
        vector<long long> shortest(n+1, LLONG_MAX);
        shortest[i] = 0;

        while (!pq.empty()) {
          auto [dist, node] = pq.top();
          pq.pop();
          //if(visited[node]) continue;
          //visited[node] = true;
          if(dist > shortest[node]) continue;

          for (auto [nei, weight] : next[node]) {
            if(dist + weight * (1 + k) < shortest[nei]) {
              shortest[nei] =  dist + weight * (1 + k);
              pq.push({shortest[nei], nei});
            }
            
          }
        }

        long long ret = LLONG_MAX;
        for(int j = 1; j <= n; ++j) {
          if(shortest[j] == LLONG_MAX) continue;
          ret = min(ret, shortest[j] + appleCost[j-1]);
        }
        res.push_back(ret == LLONG_MAX ? -1 : ret);
      }
      return res;
    }
};


/*

node weight : apple cost
only buy one apple


i -> j buy
find shortest path to each node path 

shoertest path to j * 3 + buy fee at j 
so the edge weight > 0 
used dijkstra
*/