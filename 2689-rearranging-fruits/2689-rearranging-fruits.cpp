class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
      unordered_map<int,int> basket1Cost,basket2Cost;
      int minCost = INT_MAX;
      for(auto& num : basket1) {
        minCost = min(minCost, num);
        basket1Cost[num]++;
      }

      for(auto& num : basket2) {
        minCost = min(minCost, num);
        basket2Cost[num]++;
      }
      
      vector<int> extra;

      for (auto& [cost, count] : basket1Cost) {
        if (basket2Cost.find(cost) != basket2Cost.end()) {
          int count2 = basket2Cost[cost];
          if ((count - count2)%2) {
            return -1;
          }
          if (count == count2) {
            basket2Cost.erase(cost);
          } else if (count > count2) {
            for (int i = 0; i < (count - count2)/2; i++) {
              extra.push_back(cost);
            }
            basket2Cost.erase(cost);
          } else {
            basket2Cost[cost] -= count;
          }
        } else {
          if (count%2 == 1) {
            return -1;
          }
          for (int i = 0; i < count/2; i++) {
            extra.push_back(cost);
          }
        }
      }

      for (auto& [cost, count] : basket2Cost) {
        if (count % 2 == 1) {
          return -1;
        }
        for (int i = 0; i < count/2; i++) {
          extra.push_back(cost);
        }
      }

      sort(extra.begin(), extra.end());
      long long res = 0;
      int m = extra.size();
      for (int i = 0; i < m/2; ++i) {
        res += min(extra[i], minCost * 2);
      }

      return res;
    }
};


/*


*/