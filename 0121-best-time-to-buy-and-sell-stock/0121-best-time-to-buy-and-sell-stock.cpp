class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int res = 0;
      int profit = 0;
      for (int i = 1; i< prices.size(); ++i) {
        profit = profit+ prices[i]-prices[i-1] <= 0 ? 
                 0 : 
                 profit+ prices[i]-prices[i-1];
        res = max(res, profit);
      }
      return res;        
    }
};