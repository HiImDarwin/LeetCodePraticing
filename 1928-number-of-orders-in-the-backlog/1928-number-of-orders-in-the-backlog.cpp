class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
      int M = 1e9+7;
      priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> buyQueue;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> sellQueue;
      for(auto order : orders) {
        int price = order[0];
        int amount = order[1];
        int ordertype = order[2];
        if (ordertype == 0) { 
          while (amount > 0 && !sellQueue.empty() && sellQueue.top().first <= price) {
            auto [sellprice, num] = sellQueue.top();
            sellQueue.pop();
            if(num - amount > 0) {
              sellQueue.push({sellprice,num - amount});
              amount = 0;
            } else {
              amount -= num;
            }
          }
          if(amount > 0) {
            buyQueue.push({price, amount});
          }
        }
        if(ordertype == 1) {
          while(amount > 0 && !buyQueue.empty() && buyQueue.top().first >= price) {
            auto [buyprice, num] = buyQueue.top();
            buyQueue.pop();
            if(num - amount > 0) {
              buyQueue.push({buyprice,num - amount});
              amount = 0;
            } else {
              amount -= num;
            }
          }
          if(amount > 0) {
            sellQueue.push({price, amount});
          }
        }
      }
      int res = 0;
      while(!sellQueue.empty()) {
        res += sellQueue.top().second;
        sellQueue.pop();
        res %= M;
      }
      while(!buyQueue.empty()) {
        res += buyQueue.top().second;
        buyQueue.pop();
        res %= M;
      }

      return res;
    }
};