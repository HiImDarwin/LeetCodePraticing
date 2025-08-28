class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int diff = nums.back() - nums[0]; // 所有數值都 -k 的情況
      
      for (int i = 0; i < nums.size() - 1; ++i) {
        int MAX = max(nums[i] + k, nums.back() - k);
        int MIN = min(nums[0] + k, nums[i + 1] - k);
        diff = min(diff, MAX - MIN);
      }
      return diff;
    }
};