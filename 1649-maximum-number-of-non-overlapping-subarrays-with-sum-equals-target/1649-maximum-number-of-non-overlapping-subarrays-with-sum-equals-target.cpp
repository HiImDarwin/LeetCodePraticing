class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
      int n = nums.size();
      nums.insert(nums.begin(), 0);
      vector<int> preSum(n+1,0);
      unordered_map<int,vector<int>> valIndex;

      int total = 0;
      for (int i = 0; i <= n; ++i) {
        total += nums[i];
        preSum[i] = total;
        if(valIndex.find(total) == valIndex.end()) {
          valIndex[total] = {};
        }
        valIndex[total].push_back(i);
      } 
      vector<int> dp(n+1, -1);
      dp[0] = 0;
      for (int i = 1; i <= n; ++i) {
        int need = preSum[i] - target;
        if(valIndex.find(need) != valIndex.end()) {
          for (int & needIdx :valIndex[need]) {
            if(needIdx >= i) continue;
            dp[i] = max(dp[needIdx] + 1, dp[i]);
          }
        }
        dp[i] = max(dp[i], dp[i-1]);
      }
      return dp[n];
    }
};