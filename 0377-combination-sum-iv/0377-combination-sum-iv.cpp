class Solution {
public:
    // int combinationSum4(vector<int>& nums, int target) {
    //     unordered_map<int, int> memo;
    //     return dfs(nums,target,memo);
    // }
    // int dfs(vector<int>& nums, int target, unordered_map<int, int> &memo){
    //     if(target ==0) return 1;
    //     if(target<0) return 0;
    //     if(memo.count(target)) return memo[target];
    //     int res =0;
    //     for(int num:nums) {
    //         res += dfs(nums, target -num,memo);
    //     }
    //     memo[target] = res;
    //     return res;
    // }

    int combinationSum4(vector<int>& nums, int target) {
      int n = nums.size();

      sort(nums.begin(),nums.end());
      vector<unsigned int> dp(target+1,0);

      dp[0] = 1;
      for (int sum = 1; sum <= target; ++sum) {
        for (auto& num : nums) {
          dp[sum] += (sum - num >= 0) ? dp[sum - num] : 0;
        }
      }

      return dp[target];
    }
    
};

/*
 dp[num][i] += dp[num- nums[i] * times][i-1]

*/