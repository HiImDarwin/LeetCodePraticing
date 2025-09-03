class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int total = accumulate(nums.begin(), nums.end(), 0);
      //sort(nums.begin(), nums.end());
      if (total%2 != 0) return false;
      int target = total / 2;
      vector<bool> dp(target+1, false);
      dp[0] = true;


      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > target) return false;
        for (int j = target; j >= nums[i]; j--) {
          dp[j] = dp[j] | dp[j - nums[i]];
        }
      }

      return dp[target];
    }
};