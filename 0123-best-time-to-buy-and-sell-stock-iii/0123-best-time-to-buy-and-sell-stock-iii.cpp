class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      if (n == 0) return 0;
      // for two transaction
      vector<int> left(n,0), right(n,0);
      int lowestPrice = prices[0];
      for (int i = 1; i < n; ++i) {
        lowestPrice = min(lowestPrice, prices[i]);
        left[i] = max(left[i-1], prices[i] - lowestPrice);
      }
      int highestPrice = prices[n-1];
      for (int i = n - 2; i >= 0; --i) {
        highestPrice = max(highestPrice, prices[i]);
        right[i] = max(right[i+1], highestPrice - prices[i]);
      }
      int res = 0;
      for(int i = 0; i < n; ++i) {
        res = max(res, left[i]+right[i]);
      }
      return res;
    }
};