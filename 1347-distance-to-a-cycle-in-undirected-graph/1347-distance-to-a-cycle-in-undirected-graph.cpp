class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) 
    {
      vector<vector<int>> adj(n);
      for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      vector<int> visitedDFS(n,0);
      vector<int> visitedBFS(n,0);
      queue<int> nodeQueue;
      findCycle(adj, 0, -2, visitedDFS, nodeQueue, visitedBFS);
      
      vector<int> res(n,0);
      int step = 0;
      while (!nodeQueue.empty()) {
        int size = nodeQueue.size();
        for (int i = 0; i < size; ++i) {
          int node = nodeQueue.front();
          nodeQueue.pop();
          res[node] = step;
          for (int nei : adj[node]) {
            if(visitedBFS[nei] != 1) {
              nodeQueue.push(nei);
              visitedBFS[nei] = 1;
            }
          }
        }
        step++;
      }
      return res;
    }

    int findCycle(vector<vector<int>> &adj,int node, int parent, vector<int> &visited, queue<int> &nodeQueue, vector<int> &visitedBFS) 
    {
      visited[node] = 1;
      for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        if (visited[neighbor] == 1) {
          nodeQueue.push(node);
          visitedBFS[node] = 1;
          return neighbor;
        }
        int res  = findCycle(adj, neighbor, node, visited, nodeQueue, visitedBFS);
        if (res != -1) {
          nodeQueue.push(node);
          visitedBFS[node] = 1;
          return res == node ? -1 : res;
        }
      }
      return -1;
    }

};


/*
connected undirected graph 
1 cycle

used DFS finde all cycle node
use BFS find all step to this node

*/