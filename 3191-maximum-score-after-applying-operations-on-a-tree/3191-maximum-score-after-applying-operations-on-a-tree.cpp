class Solution {
  vector<int> next[20005];
  long long subtreeSum[20005];
  vector<int> values;
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
      this->values = values;
      for (auto& edge: edges) {
        int a = edge[0], b = edge[1];
        next[a].push_back(b);
        next[b].push_back(a);
      }
      dfsSum(0,-1);
      return dfs(0, -1);

    }
    long long dfsSum(int curr, int parent) {

      long long sum = 0;
      if(next[curr].size() != 1 || curr == 0) {
        for(int neighbor : next[curr]) {
          if (neighbor == parent) continue;
          sum += dfsSum(neighbor, curr);
        }
      }

      subtreeSum[curr] = sum;
      return sum + values[curr];
    }
    long long dfs(int curr ,int parent) {
      if(next[curr].size() == 1 && curr !=0) {
        return 0;
      }
      long long sum = values[curr];
      for (int nxt: next[curr]) {
        if (nxt == parent) continue;
        sum += dfs(nxt ,curr);
      }

      return max(sum, subtreeSum[curr]);
    }
};

/*
zero is the root


*/