class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
      const int MAX_SUM = 5000;

      bitset<5001> dp;
      dp.reset();
      dp[0] = 1;
      
      for (auto& row : mat) {
        bitset<5001> next;
        for (auto& num : row) {
          next |= (dp << num);
        }
        dp = next;
      }

      int res = INT_MAX;
      for (int s = 0; s <= MAX_SUM; s++) {
        if(dp[s]) {
          res = min(res, abs(s - target));
        }
      }
      
      return res;
    }
};