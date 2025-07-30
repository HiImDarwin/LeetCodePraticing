class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      vector<vector<pair<int,int>>> adj(n);
      for(auto road : edges) {
        int u = road[0], v = road[1], w= road[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
      }
      vector<int> city(n,0);
      for(int i = 0; i < n; ++i) {
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,i});
        dist[i] = 0;
        while (!pq.empty()) {
          auto [curDist, curCity] = pq.top();
          pq.pop();
          if( curDist > dist[curCity]) continue;
          city[i]++;
          for (auto [nei, travel] : adj[curCity]) {
            if(curDist + travel <= distanceThreshold && curDist + travel < dist[nei]) {
              dist[nei] = curDist + travel;
              pq.push({dist[nei], nei});
            }
          }
        }
      }
      int res = 0;
      int count = n;
      for (int i = 0; i < n; ++i) {
        cout <<  city[i] << endl;
        if(city[i] <= count) {
          res = i;
          count = city[i];
          
        }
      }

      return res;
    }
};