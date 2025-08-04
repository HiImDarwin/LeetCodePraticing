class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      if (n==0) return {};
      vector<int>dp(n,1);
      vector<int>prev(n,-1);

      int maxLen = 0;
      int maxIndex = -1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (nums[i] % nums[j] == 0) {
            dp[i] = max(dp[i], dp[j] + 1);
            if (dp[i] == dp[j] + 1) {
              prev[i] = j;
            }
            if (dp[i] > maxLen) {
              maxLen = dp[i];
              maxIndex = i;
            }
          }
        }
      }
      vector<int> res;
      while (maxIndex != -1) {
        res.push_back(nums[maxIndex]);
        maxIndex = prev[maxIndex];
      }
      return res;

     

      
    }
};


/*
a nums can be in sevel different subset
dp[i] points to a vetor
for(every dp[i-1])

*/