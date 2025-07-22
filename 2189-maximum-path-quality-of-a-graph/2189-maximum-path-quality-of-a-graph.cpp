class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> visited(n,0);
        for(auto edge : edges) {
          adj[edge[0]].push_back({edge[1],edge[2]});
          adj[edge[1]].push_back({edge[0],edge[2]});
        }
        int res = 0;
        dfs(0, 0, values, 0, res, maxTime, adj, visited);
        return  res;
    }

    void dfs(int node, int totalVal, vector<int>& values, int totalTime, int &res, const int &maxTime, vector<vector<pair<int,int>>> &adj,vector<int> &visited) {
      if(totalTime > maxTime) return;
     
      if(visited[node] == 0) {
        totalVal += values[node];
      } 
      visited[node]++;
      if(node == 0) res = max(res,totalVal);
      for(auto [neighbor , time] : adj[node]) {
        dfs(neighbor, totalVal, values, totalTime + time, res, maxTime, adj, visited);
      }
      visited[node]--;
      
    }
};


 /*
  undirected graph
  node have value
  n node
  edge with weight
  node can visit more than 1 times
  quelity is the  sum of node value
  travel with time limitation



  time complexity ?


 */