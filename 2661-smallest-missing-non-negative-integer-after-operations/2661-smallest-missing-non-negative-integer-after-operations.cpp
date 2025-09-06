class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
      vector<int> remainderCount(value,0);
      for (auto& num : nums) {
        int r = num % value;
        if (r < 0) {
          r += value;
        }
        remainderCount[r]++;
      }
      int minCount = INT_MAX;
      int minValue = -1;
      for (int i = 0; i < value; i++) {
        if (remainderCount[i] < minCount) {
          minCount = remainderCount[i];
          minValue = i;
        }
      }
      return value * (minCount) + minValue;

    }
};
/*
record count for each remainder
0 ~ value - 1



*/