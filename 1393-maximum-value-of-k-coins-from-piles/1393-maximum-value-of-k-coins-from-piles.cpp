class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
      int n = piles.size();
      vector<vector<long long>> pileSum(n,vector<long long>(1,0));

      for (int i = 0; i < n; i++) {
        // for (int j = 0; j < pileSum[i].size(); j++) {
        //   pileSum[i].push_back(pileSum[i].back() + piles[i][j]);
        // }
        for (auto& coin : piles[i]) {
          pileSum[i].push_back(pileSum[i].back() + 1LL * coin);
        }
      }

      vector<vector<long long>> dp(n +1, vector<long long>(k + 1, 0));
      for(int i = 1; i <= n; i++) {
        for (int coins = 1; coins <= k; coins++) {
          for (int t = 0; t <= min((int)piles[i - 1].size(), coins); t++) {
            dp[i][coins] = max(dp[i][coins], dp[i - 1][coins - t] + pileSum[i- 1][t]);
          }
        }
      }
      return dp[n][k];
    }
};

/*
pilesVal[i][t]就是第i根pile取t个硬币的收益
dp[i][j] = max{dp[i-1][j-t] + pilesVal[i][t]} i 表示   0~i 根 pile 中 j 表示 取coin總數 
                                                where t= 0,1,2,...,len(piles[i])


*/