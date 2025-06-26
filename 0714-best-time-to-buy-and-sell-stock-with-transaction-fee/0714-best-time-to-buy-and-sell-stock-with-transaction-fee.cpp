class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
      int n = prices.size();
        vector<int> hold(n, INT_MIN),sold(n, INT_MIN);
        hold[0] = -prices[0];
        sold[0] = 0;
        for (int i = 1; i < n; ++i) {
          hold[i] = max(sold[i-1] - prices[i], hold[i-1]);
          sold[i] = max(hold[i-1]+ prices[i] - fee, sold[i-1]);
        }
        return sold[n-1];
    }
};

// 在i要是持有股票 與 在i要是不持有股票
//hold[i] = max(sold[i-1] - price[i], hold[i-1]);
//sold[i] = max(hold[i-1]+ price[i] - fee, sold[i-1]);
