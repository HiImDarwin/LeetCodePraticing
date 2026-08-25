class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxEarn = 0;
      int lowestPrice = prices[0];
      for (int price : prices) {
        maxEarn = max(maxEarn, price - lowestPrice);
        lowestPrice = min(lowestPrice, price);
      }
      return maxEarn;
    }
};


// continuous array sum > 0
//