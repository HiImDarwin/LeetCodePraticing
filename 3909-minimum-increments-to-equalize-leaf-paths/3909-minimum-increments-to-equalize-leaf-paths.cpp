class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n,false);
        //O(E)
        for(auto edge : edges) {
          int u = edge[0];
          int v = edge[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        int equalCostPath = 0;
        int editNode = 0;
        DFS(0, adj, cost, visited, editNode);
        return editNode;
    }

    long long DFS(int node, unordered_map<int,vector<int>> &adj, vector<int>& cost, vector<bool> &visited, int &editNode) {
      long long  maxPathVal = 0;
      int maxPathCount = 0;
      int pathCount = 0;
      visited[node] = true;
      for(auto neighbor : adj[node]) {
        if(!visited[neighbor]) {
          long long pathVal = DFS(neighbor, adj, cost, visited, editNode);
          pathCount++;
          if(pathVal > maxPathVal) {
            maxPathVal = pathVal;
            maxPathCount = 1;
          } else if (pathVal == maxPathVal) {
            maxPathCount++;
          }
        }
      }
      editNode += pathCount - maxPathCount;
      return maxPathVal + cost[node];
    }
};

/*
undirected 
 n node root 0
 weight edge


 all path scre equal
 maximum num of adding node is leafNum-1; 
 if two node have same value need to add
 add at their LCA but need an additional condition
 other subtree under this LCA need more cost then that


 DFS because the root need to see every subtree conditino to decide 
 [ 1 2 3 3 2 5 6 10 5]
*/