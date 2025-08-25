class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<int> dist(n,INT_MAX/2);
      dist[src] = 0;
      for (int i = 0; i <= k; ++i) {
        vector<int> tmp = dist;
        for (auto& flight : flights) {
          int u = flight[0];
          int v = flight[1];
          int cost = flight[2];
          tmp[v] = min(tmp[v], dist[u] + cost); 
        }
        dist = tmp;
      }
      return dist[dst] == INT_MAX/2 ? -1 : dist[dst];
    }
};

/*
dijkstra
  piority_queue with adj list
bellman ford

floyd warshall
shortest path with k rounds relaxing


*/