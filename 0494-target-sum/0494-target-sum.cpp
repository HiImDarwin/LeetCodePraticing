class Solution {
public:
    // int findTargetSumWays(vector<int>& nums, int target) {
    //   int n = nums.size();
    //   int total = 0;

    //   unordered_map<int,int> map;
    //   backtracking(map, nums, 0, 0);

    //   return map[target];
    // }

    // void backtracking( unordered_map<int,int> &map, vector<int>& nums, int idx, int sum) {
    //   if(idx == nums.size()) {
    //     map[sum]++;
    //     return;
    //   }
    //   backtracking(map, nums, idx+1, sum + nums[idx]);
    //   backtracking(map, nums, idx+1, sum - nums[idx]);
    // }


    int findTargetSumWays(vector<int>& nums, int target) {
      unordered_map<int,int> mp;
      mp[0] = 1;
      for (int i = 0; i < nums.size(); i++) {
        unordered_map<int,int> tmp;
        for (auto& [sum, count] : mp) {
          tmp[sum + nums[i]] += count;
          tmp[sum - nums[i]] += count;
        }
        mp = tmp;
      }
      return mp[target];
    }
};