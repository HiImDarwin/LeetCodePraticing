class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<unordered_set<int>> adj(n);
        for(auto &edge : edges) {
          adj[edge[0]].insert(edge[1]);
          adj[edge[1]].insert(edge[0]);
        }
        vector<int> degree(n);
        queue<int> qu;
        for(int i = 0; i < n; ++i) {
          degree[i] = adj[i].size();
          if(degree[i]  == 1) qu.push(i);
        }
        

        int nodeNum = n;
        while(nodeNum > 2) {
          int queueSize =  qu.size();
          while(queueSize > 0) {
            int node = qu.front(); qu.pop();
            queueSize--;
            nodeNum--;
            for(int nei : adj[node]) {
              degree[nei]--;
              if(degree[nei] == 1) qu.push(nei);
            }
          }
        }
        vector<int> res;
        while(!qu.empty()) {
          res.push_back(qu.front());
          qu.pop();
        }
        return res;
    }


};