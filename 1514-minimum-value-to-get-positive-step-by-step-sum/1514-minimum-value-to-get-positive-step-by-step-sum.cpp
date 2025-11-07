class Solution {
public:
    int minStartValue(vector<int>& nums) {
      int sum = 0;
      int minVal = INT_MAX;
      for (auto num : nums) {
        sum += num;
        minVal = min(minVal, sum);
      }
      return max(-minVal + 1, 1);
    }
};


/*



*/