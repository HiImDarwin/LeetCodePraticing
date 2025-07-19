class Solution {
  struct large{
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
      return a.first > b.first;
    }
  };
public:
    long long maxSpending(vector<vector<int>>& values) {
      int m = values.size();
      int n = values[0].size();
      priority_queue<pair<int,int>,vector<pair<int,int>>,large> pq;
      vector<int> pos(m,n-1);
      for(int i = 0; i < m; ++i) {
        pq.push({values[i][pos[i]], i});
        pos[i]--;
      }
      long long res = 0;
      int dayI = 1;
      while(!pq.empty()) {
        auto [val, index] = pq.top();
        pq.pop();

        res += 1LL*val*(dayI++);
        if (pos[index] >= 0) {
          pq.push({values[index][pos[index]], index});
          pos[index]--;
        }
      }
      return res;
    }
};