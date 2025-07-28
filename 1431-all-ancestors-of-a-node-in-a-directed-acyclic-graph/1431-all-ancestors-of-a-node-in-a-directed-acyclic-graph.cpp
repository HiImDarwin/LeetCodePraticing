class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
      vector<bitset<1000>> ancestorMap(n);
      vector<int> inDegree(n,0);
      vector<vector<int>> next(n);

      for (auto edge : edges) {
        int from = edge[0];
        int to   = edge[1];
        inDegree[to]++;
        next[from].push_back(to);
      }

      queue<int> nodeQueue;
      //vector<bool> visited(n);

      for (int i = 0; i < n; ++i) {
        //ancestorMap[i].set(i,true);
        if (inDegree[i] == 0) {
          nodeQueue.push(i);
          //visited[i] = true;
        }
      }

      while (!nodeQueue.empty()) {
        int curr = nodeQueue.front();
        nodeQueue.pop();
        
        for (int nextNode : next[curr]) {
          inDegree[nextNode]--;
          ancestorMap[nextNode] |= ancestorMap[curr];
          ancestorMap[nextNode].set(curr);
          if(inDegree[nextNode] == 0) {
            nodeQueue.push(nextNode);
          }
        }
      }
      vector<vector<int>> res;
      for (int i = 0; i < n; ++i) {
        vector<int> tmp;
        for (int j = 0; j < n; ++j) {
          if(ancestorMap[i][j]) {
            tmp.push_back(j);
          }
        }
        res.push_back(tmp);
      }
      return res;
    }
};

/*

direct 
acyclic

*/