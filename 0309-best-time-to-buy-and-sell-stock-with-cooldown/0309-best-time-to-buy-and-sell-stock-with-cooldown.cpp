class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int> sold(n+1, 0),hold(n+1, 0);
      hold[1] = -prices[0];
      for (int i = 2; i <= n; ++i) {
        sold[i] = max(sold[i-1], hold[i-1] + prices[i-1]);
        hold[i] = max(hold[i-1], sold[i-2] - prices[i-1]);
      }
      return sold[n];
    }
};