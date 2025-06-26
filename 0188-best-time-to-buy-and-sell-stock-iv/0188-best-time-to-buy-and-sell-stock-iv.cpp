class Solution {
public:
    int n;
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        if (n == 0 || k == 0) return 0;
        
        if (k >= n/2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
        vector<vector<int>> dp(k+1, vector<int> (n ,0)); // 交易k次第i天的最大利潤
        for (int t = 1; t <= k; ++t) {
            int maxProfitAfterBuy  = dp[t-1][0] - prices[0];
            for (int i = 1; i < n; ++i) {
                dp[t][i] = max(dp[t][i-1], prices[i] + maxProfitAfterBuy);
                maxProfitAfterBuy = max (maxProfitAfterBuy, dp[t-1][i] - prices[i]);
            }
        }
        return dp[k][n-1];
    }

};