class Solution 
{   
    int MOD = 1e9 + 7;
  public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
      
      int m = group.size();
      vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,0)));
      dp[0][0][0] = 1;
      group.insert(group.begin(),0);
      profit.insert(profit.begin(),0);

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
          for (int k = 0; k <= minProfit; ++k) {
            
            dp[i + 1][j][k] += dp[i][j][k];
            dp[i + 1][j][k] %= MOD;


            if (j + group[i + 1] <= n) {
              dp[i + 1][j + group[i + 1]][min(minProfit, k + profit[i + 1])] += dp[i][j][k];
              dp[i + 1][j + group[i + 1]][min(minProfit, k + profit[i + 1])] %= MOD;
            }

          }
        }
      }
      int res =0;
      for (int j = 0; j <= n; ++j) {
        res = (res + dp[m][j][minProfit]) % MOD; 
      }
      return res;
    }
};



/*
recursive

  for(int i)
    for(int j)

  dp[i][person][profit] = dp[i-1][person][profit] + dp[i-1][person-group[i]][profit-protif[i]]
  


  dp[i+1][j][k] += dp[i][j][k];
            dp[i+1][j][k] %= MOD;
            if (j+group[i+1] > n) {
              continue;
            }
            dp[i+1][j+group[i+1]][min(k+profit[i+1],minProfit)] += dp[i][j][k];
            dp[i+1][j+group[i+1]][min(k+profit[i+1],minProfit)] %= MOD;

*/