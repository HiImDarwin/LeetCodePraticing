class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int res = 0;
      int low_price = prices[0];
      for(int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i-1]) continue;
        res += prices[i-1] < low_price ? 0 : prices[i-1] - low_price;
        low_price = prices[i];
      }
      res += prices[prices.size()-1] < low_price ? 
             0 : 
             prices[prices.size()-1] - low_price;
      return res;
    }
};