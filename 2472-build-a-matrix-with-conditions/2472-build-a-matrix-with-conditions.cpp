class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
      vector<int> row = topo(k, rowConditions);
      vector<int> col = topo(k, colConditions);

      if(row.empty() || col.empty()) return {};

      vector<pair<int,int>> pos(k+1);
      for (int i = 0; i < k; ++i) {
        pos[row[i]].first = i;
      }
      for (int j = 0; j < k; ++ j) {
        pos[col[j]].second = j;
      }
      vector<vector<int>> matrix(k, vector<int>(k,0));
      for(int i = 1; i <= k; ++i) {
        matrix[pos[i].first][pos[i].second] = i;
      }
      return matrix;
    }

    vector<int> topo(int k, vector<vector<int>> &condition) 
    {
      vector<int> indegree(k+1);
      vector<vector<int>> next(k+1);
      for (auto& x: condition) {
        next[x[0]].push_back(x[1]);
        indegree[x[1]]++;
      }

      queue<int> q;
      for (int i = 1; i <= k; ++i) {
        if (indegree[i] == 0) {
          q.push(i);
        }
      }
      vector<int> res;
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (auto x: next[cur]) {
          indegree[x]--;
          if (indegree[x] == 0) {
            q.push(x);
          }
        }
      }
      if (res.size() != k) return {};
      return res;
    }
};


