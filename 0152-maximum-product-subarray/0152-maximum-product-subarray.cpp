class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      int maxSoFar = nums[0];
      int minSoFar = nums[0];
      int res = maxSoFar;
      for (int i = 1; i < n; ++i) {
        int curr = nums[i];
        int tmp_max = max(curr, max(maxSoFar * curr, minSoFar* curr));
        minSoFar = min(curr, min(maxSoFar * curr, minSoFar* curr));

        maxSoFar = tmp_max;
        res = max(res, maxSoFar);
      }
      return res;
    }
};

/*
the maximum is according to prev num
dp[i][2]

*/