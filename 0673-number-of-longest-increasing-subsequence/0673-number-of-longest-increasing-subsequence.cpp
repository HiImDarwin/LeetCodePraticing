class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<pair<int,int>> dp(n,{1,1}); //length num
      int maxlen = 1;
      unordered_set<int> maxIndex;
      maxIndex.insert(0);

      for(int i = 1; i < n; i++) {
        int count = 1;
        for (int j = 0; j < i; j++) {
          if(nums[j] < nums[i]) {
            if(dp[j].first + 1 > dp[i].first) {
              dp[i].first = dp[j].first + 1;
              dp[i].second = dp[j].second;
            } else if (dp[j].first + 1 == dp[i].first) {
              dp[i].second += dp[j].second;
            }
          }
        }
        if (dp[i].first > maxlen) {
          maxlen = dp[i].first;
          maxIndex.clear();
          maxIndex.insert(i);
        } else if (dp[i].first == maxlen) {
          maxIndex.insert(i);
        }
      }
      int res = 0;

      for(int idx : maxIndex) {
        res += dp[idx].second;
      }
      return res;
    }
};