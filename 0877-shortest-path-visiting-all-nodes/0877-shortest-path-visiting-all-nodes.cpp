class Solution {
  vector<vector<bool>> states;
public:
    int shortestPathLength(vector<vector<int>>& graph) {
      int n = graph.size();
      int target = (1 << n) - 1;
      states.resize(n, vector<bool>(1 << n, false));
      queue<pair<int,int>> qu; // node state
      for (int i = 0; i < n; i++) {
        qu.push({i, 1 << i});
        states[i][1 << i] = true;
      }
      int step = 0;
      while (!qu.empty()) {
        int len = qu.size();
        while (len--) {
          auto [node, state] = qu.front();
          qu.pop();
          if (state == target) {
            return step;
          }
          for (auto nei : graph[node]) {
            int newState = state | (1 << nei);
            if (states[nei][newState]) {
              continue;
            }
            qu.push({nei, newState});
            states[nei][newState] = true;
          }
        }
        step++;
      }
    
      return -1;
    }
};

/*
1. find the middle node in the lca (because it can build a tree with minimun height)
  BFS with edge
2. dfs from that node
3. res = path sum 
因為後面才發現圖不是 tree 應此前面LCA 或是 longest path 的思維就沒了

multistate



*/