class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();
      long res = 0;
      vector<unordered_map<long,int>> dp(n);
      for (int i = 1; i< n; i++) {
        for (int j = 0; j < i; j++) {
          long diff = 1L * nums[i] - 1L * nums[j];
          int cnt = dp[j].find(diff) == dp[j].end() ? 0 : dp[j][diff];
          res += cnt;
          dp[i][diff] += cnt + 1;
        }
      }
      return res;
    }
};


/*
diff 要固定
每個element可以跟前面的不同element組成 不同diff的sub array
dp[i][diff] 是指index i 有多少差為 diff 的 sub sequence

*/