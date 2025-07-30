class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
      this->n = n;
      dist.resize(n,vector<int>(n,INT_MAX/3));
      for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
      }
      for (auto e : edges) {
        int u = e[0], v = e[1], w = e[2];
        dist[u][v] = w;
      }

      for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
          }
        }
      }
    }
    
    void addEdge(vector<int> edge) {
      int u = edge[0], v = edge[1], w = edge[2];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][u] + w + dist[v][j]);
        }
      }
        
    }
    
    int shortestPath(int node1, int node2) {
      int res =dist[node1][node2];
      return res == INT_MAX/3 ? -1 : res;
    }

  private:
    vector<vector<int>> dist;
    int n;

};




/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */


