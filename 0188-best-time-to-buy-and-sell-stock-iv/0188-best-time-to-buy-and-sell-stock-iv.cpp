class Solution {
  public:
    
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     if (n == 0 || k == 0) return 0;
        
    //     if (k >= n/2) {
    //         int profit = 0;
    //         for (int i = 1; i < n; ++i) {
    //             if (prices[i] > prices[i - 1]) {
    //                 profit += prices[i] - prices[i - 1];
    //             }
    //         }
    //         return profit;
    //     }
    //     vector<vector<int>> dp(k+1, vector<int> (n ,0)); // 交易k次第i天的最大利潤
    //     for (int t = 1; t <= k; ++t) {
    //         int maxProfitAfterBuy  = dp[t-1][0] - prices[0];
    //         for (int i = 1; i < n; ++i) {
    //             dp[t][i] = max(dp[t][i-1], prices[i] + maxProfitAfterBuy);
    //             maxProfitAfterBuy = max (maxProfitAfterBuy, dp[t-1][i] - prices[i]);
    //         }
    //     }
    //     return dp[k][n-1];
    // }

    int maxProfit(int k, vector<int>& prices) {
      int n = prices.size();

      if( k >= n / 2){
        int profit = 0;
        for(int i = 1; i < n; ++i) {
          profit += prices[i] > prices[i-1] ?
                    prices[i] - prices[i-1] :
                    0;
        }
        return profit;
      }

      vector<int> hold(k+1, INT_MIN/2);
      vector<int> sold(k+1, INT_MIN/2);

      hold[0] = 0;
      sold[0] = 0;

      for (int i = 0; i < n; ++i) {
        auto hold_old = hold;
        auto sold_old = sold;
        for(int j = 1; j <= k; ++j) {
          hold[j] = max (sold_old[j-1]-prices[i], hold_old[j]);
          sold[j] = max (hold_old[j]+prices[i], sold_old[j]);
        }
      }

      int res = INT_MIN;
      for (int j = 0; j <= k; ++j) {
        res = max(res, sold[j]);
      }
      return res;
    }

};