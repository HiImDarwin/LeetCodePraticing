class Solution {
    int n;
public:
    // bool checkEqualPartitions(vector<int>& nums, long long target) {
    //   n = nums.size();
    //   return dfs(nums, 0, 1, 1, target);
    // }


    // bool dfs(vector<int>& nums, int index, long long sum1, long long sum2, const long long& target) {
      
    //   if (target%sum1 != 0  || target%sum2 != 0) return false;
    //   if (index == n && sum1 == target && sum2 == target) return true;
    //   if (index == n) return false;
      
    //   if (dfs(nums, index + 1, sum1 * nums[index], sum2, target)) {
    //     return true;
    //   }
    //   if (dfs(nums, index + 1, sum1, sum2 * nums[index], target)) {
    //     return true;
    //   }
    //   return false;
    // }
    typedef __int128 ll;
    bool checkEqualPartitions(vector<int>& nums, long long target) {
      int n = nums.size();
      ll ans = 1;
      for (auto it: nums) {
        ans *= it;
        if (ans > (ll)target * target) return false;
      }

      if (ans != (ll)target * target) return false;
      
      int maxi = (1 << n);
      vector<long long> prod(maxi, -1);
      prod[0] = 1;
      for (int i = 1; i < maxi - 1; ++i) {
        int highest = 31 - __builtin_clz(i);
        int prevMask = i ^ (1 << highest);
        prod[i] = prod[prevMask] * nums[highest];
        if (prod[i] == target) return true;
      }
      
      return false;
    }
};

/*

*/