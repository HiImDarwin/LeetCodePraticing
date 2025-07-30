class Solution {
public:
    int longestCycle(vector<int>& edges) 
    {
      int n= edges.size();
      vector<int> indegree(n,0);
      for (int & edge: edges) {
        if(edge == -1) continue;
        indegree[edge]++;
      }
      queue<int> nodeQu;
      vector<bool> visited(n,false);
      for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
          nodeQu.push(i);
        }
      }
      while (!nodeQu.empty()) {
        int node = nodeQu.front();
        nodeQu.pop();
        visited[node] = true;
        if(edges[node] == -1) continue;
        indegree[edges[node]]--;
        if(indegree[edges[node]] == 0) {
          nodeQu.push(edges[node]);
        }
      }
      int res = -1;
      for (int i = 0; i < n;  ++i) {
        if (visited[i]) continue;
        res = max(res,dfs(i,edges,visited));
      }
      return res;
    }
    
    int dfs(int node, vector<int> &edges, vector<bool> &visited)
    {
      visited[node] = true;

      if(visited[edges[node]]) return 1;
      return dfs(edges[node], edges, visited) + 1;
    }
};



/*
only one edge 影響什麼？ 每個節點只有一條分對外分支 
若不是單鏈就是環
將indegree = 0 的點開始清除點上的degree
那麼最後剩下的點都是環




*/