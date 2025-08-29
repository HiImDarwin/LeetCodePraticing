class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
      vector<int> pre(n, 0);
      for (auto& e : edges) {
        pre[e[1]] |= 1 << e[0];
      }

      vector<int> dp(1 << n, -1);
      dp[0] = 0;
      for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] == -1) continue;
        int pos = __builtin_popcount(mask) + 1;
        for (int i = 0; i < n; i++) {
          if (((mask >> i) & 1) == 0 && (mask & pre[i]) == pre[i]) {
            int mask2 = mask | (1 << i);
            dp[mask2] = max(dp[mask2], dp[mask] + score[i] * pos);
          }
        }
      }
      return dp[(1 << n) - 1];
    }
};


/*
valid topological order
node 1-base position
is it guaranteed to be DAG?
duplicate edges?

may have multiple topological order

DP[i]
 0 1 | 2 3 | 4 5 6 7

 2 3 | 0 1 | 4 5 6 7


dp[mask∣(1<<next)]=max(dp[mask∣(1<<next)],dp[mask]+score[next])
*/