class Solution {
    int n;
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
      n = nums.size();
      return dfs(nums, 0, 1, 1, target);
    }


    bool dfs(vector<int>& nums, int index, long long sum1, long long sum2, const long long& target) {
      
      if (target%sum1 != 0  || target%sum2 != 0) return false;
      if (index == n && sum1 == target && sum2 == target) return true;
      if (index == n) return false;
      
      if (dfs(nums, index + 1, sum1 * nums[index], sum2, target)) {
        return true;
      }
      if (dfs(nums, index + 1, sum1, sum2 * nums[index], target)) {
        return true;
      }
      return false;
    }
};

/*

*/