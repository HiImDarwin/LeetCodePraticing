class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
      int left = *max_element(weights.begin(), weights.end());
      int right = accumulate(weights.begin(), weights.end(), 0);
      while (left < right) {
        int limit = left +(right - left) / 2;
        if (check(limit, weights, days)) {
          right = limit;
        } else {
          left = limit + 1;
        }
      } 
      return left;
    }

    bool check (int limit, vector<int>& weights, int days) {
      int sum = 0;
      int dayCount = 1;
      for (int& weight : weights) {
        if (sum + weight > limit) {
          dayCount++;
          sum = 0;
        }
        sum += weight;
      }
      return dayCount <= days;
    }
};