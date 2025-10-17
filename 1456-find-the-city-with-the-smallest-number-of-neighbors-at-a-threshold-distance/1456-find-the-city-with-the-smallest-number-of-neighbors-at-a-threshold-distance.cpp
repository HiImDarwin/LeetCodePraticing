class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      vector<vector<int>> dist(n, vector<int>(n, INT_MAX/2));
      for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
      }
      for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int distance = edge[2];
        dist[u][v] = distance;
        dist[v][u] = distance;
      }
      floydWarshell(dist,edges);
      int minCount = INT_MAX;
      int city = -1;
      for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
          if (i == j) continue;
          if (dist[i][j] <= distanceThreshold) {
            count++;
          }
        }
        if (count <= minCount) {
          minCount = count;
          city = i;
        }
      }
      return city;
    }


    void floydWarshell(vector<vector<int>>& dist, vector<vector<int>>& edges) {
      int n = dist.size();
      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
};

/*
bidirectional
is there self edge?
is the grapch connected?
is there parallel edge?


floyd warshell (v^3)
dijkstra(ElogE)
*/