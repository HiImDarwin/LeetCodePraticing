class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int low_price = prices[0];
      int high_price  = prices[0];
      int res = 0;
      for(int i = 1; i < prices.size(); ++i) {
        if(prices[i] < high_price) {
          res += high_price-low_price;
          low_price = prices[i];
          high_price = prices[i];
        } else {
          high_price = prices[i];
        }
      }
      res += high_price -low_price;
      return res;
    }
};