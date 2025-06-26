typedef long long ll;
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
      int n = prices.size();
      if (n < 2 || k == 0) return 0;

      vector<ll> dp_prev(n, 0), dp_curr(n, 0);

      for (int t = 1; t <= k; ++t) {
        ll bestBuy = -prices[0];
        ll bestShort = prices[0];
        dp_curr[0] = 0;

        for (int i = 1; i < n; ++i) {
          ll doNothing = dp_curr[i - 1];
          ll sellAfterBuy = bestBuy + prices[i];
          ll buyBackAfterShort = bestShort - prices[i];

          dp_curr[i] = max({doNothing,sellAfterBuy,buyBackAfterShort});
        
          bestBuy = max(bestBuy, dp_prev[i-1] - prices[i]);
          bestShort = max(bestShort, dp_prev[i-1] + prices[i]);
        
        }
        dp_prev.swap(dp_curr);
      }
      
      return dp_prev[n-1];
      // profit[i] = max (profit[j] + preBuy[j][i], profit[j] + preSell[j][i]); j = 0 ~ i 
    }
};