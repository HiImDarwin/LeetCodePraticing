class Solution {
  public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();
      long long ans = 0;
      map<long long, int> dp[1000];
      int count = 0;

      for (int i = 1; i < n; i ++) {
        for (int j = i - 1; j >= 0; j--) {
          long long diff = (long long)nums[i] - (long long)nums[j];
          count += dp[j][diff];


          dp[i][diff] += dp[j][diff] + 1;

        }
      }
      return count;
    }
};
/*
dp[i][d]
subsequence ed at i and diff is d
if (nums[i] - d exist) dp[i] = dp[nums[i] - d] + 1;
for all 
[a,b,c,d,e] 
diff:  difference between any two consecutive elements 

1. find max length for each diff
2. count the subsequence for each diff

*/