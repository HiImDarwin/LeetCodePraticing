class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      int res = 0;
      while(numBottles >= numExchange) {
        int left = numBottles % numExchange;
        int empty = numBottles - left;
        res += empty;
        numBottles = left + empty/numExchange;
      }
      res += numBottles;
      return res;
    }
};