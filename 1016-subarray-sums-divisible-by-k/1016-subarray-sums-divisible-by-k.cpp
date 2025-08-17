class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      vector<int> remainder(k,0);
      remainder[0] = 1;
      long long preSum = 0;
      int res = 0;
      for (int i = 0; i < nums.size(); ++i) {
        preSum += nums[i];
        int r = (preSum % k + k) % k;
        res += remainder[r];
        remainder[r]++;
      }
      return res;
    }
};