class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      vector<int> color(graph.size(),-1);
      queue<int> nodeQu;

      for (int i = 0; i < graph.size(); ++i) {
        // check if graph have  several components
        if(color[i] == -1) {
          nodeQu.push(i);
          color[i] = 0;
        }
        // color the component
        while (!nodeQu.empty()) {
          int node = nodeQu.front(); 
          nodeQu.pop();
          for (auto neighbor : graph[node]) {
            if(color[neighbor] == -1) {
              color[neighbor] = (color[node] + 1) % 2;
              nodeQu.push(neighbor);
            } else if (color[neighbor] == color[node]) {
              return false;
            }
          }
        }
      }
      
      return true;
    }
};

/*
undirected
no self edge


*/