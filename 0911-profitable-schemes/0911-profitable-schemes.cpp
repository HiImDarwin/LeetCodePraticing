class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
      vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1, 0));
      dp[0][0] = 1;
      int res = 0;
      int mod = 1e9 + 7;
      for (int k = 0; k < group.size(); k++) {
        int g = group[k], p = profit[k];
        for (int i = minProfit; i >= 0; i--) {
          for (int j = n - g; j >= 0; j--) {
            dp[min(i + p, minProfit)][j + g] =  (dp[min(i + p, minProfit)][j + g] + dp[i][j]) % mod;
          }
        }
      }

      for (int x: dp[minProfit]){
        res = (res + x) % mod;
      } 
      return res;
    }
};

/*
profitable scheme any subset of these crimes that generates at least minProfit profit

dp[profit][n] =  profitable scheme under i profi and j member
dp[i + p][j + g] += dp[i][j] if i + p < P
dp[P][j + g] += dp[i][j] if i + p >= p
we don't know the max of profit 



*/