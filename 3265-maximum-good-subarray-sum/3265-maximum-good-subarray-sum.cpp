class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      unordered_map<int,long long> freq;
      long long res = LLONG_MIN;
      long long preSum = 0;
      for (int i = 0; i < nums.size(); i++) {
        preSum += nums[i];

        if (freq.find(nums[i] - k) != freq.end()) {
          long long val = preSum - freq[nums[i] - k] + nums[i] - k;
          res = max(res, val);
        }
        if (freq.find(nums[i] + k) != freq.end()) {
          long long val = preSum - freq[nums[i] + k] + nums[i] + k;
          res = max(res, val);
        }

        if (freq.find(nums[i]) == freq.end() || preSum < freq[nums[i]]) {
          freq[nums[i]] = preSum;
        } 
      }
      return res == LLONG_MIN ? 0 : res;
    }
};

/*

prefixSum


*/