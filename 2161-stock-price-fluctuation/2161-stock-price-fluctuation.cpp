class StockPrice {
  public:
    StockPrice() {
      currStuck = {-1,-1};
    }
    
    void update(int timestamp, int price) {
      if (stockMap.find(timestamp) != stockMap.end()) {
        if (stockMap[timestamp] == price) return;
        lazyDeleteMax.insert({timestamp, stockMap[timestamp]});
        lazyDeleteMin.insert({timestamp, stockMap[timestamp]});
      }

      stockMap[timestamp] = price;
      maxQu.push({price, timestamp});
      minQu.push({price, timestamp});
      if (currStuck.first <= timestamp) {
        currStuck = {timestamp, price};
      }
    }
    
    int current() {
      return currStuck.second;
    }
    
    int maximum() {   
      while (lazyDeleteMax.find({maxQu.top().second, maxQu.top().first}) != lazyDeleteMax.end()) {
        lazyDeleteMax.erase({maxQu.top().second,maxQu.top().first});
        maxQu.pop();
      }
      return maxQu.top().first;
    }
    
    int minimum() {
      while (lazyDeleteMin.find({minQu.top().second, minQu.top().first}) != lazyDeleteMin.end()) {
        lazyDeleteMin.erase({minQu.top().second, minQu.top().first});
        minQu.pop();
      }
      return minQu.top().first;
    }
  private:
    pair<int,int> currStuck;
    unordered_map<int,int> stockMap;
    priority_queue<pair<int,int>> maxQu; 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minQu;
    set<pair<int,int>> lazyDeleteMax,lazyDeleteMin;
};


/*
only one stock
key timestamp
come in not in order

*/

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */