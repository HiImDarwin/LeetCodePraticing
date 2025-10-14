class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
      int n = nums.size();
      long long sum = accumulate(nums.begin(), nums.end(), 0LL);
      int times = target / sum;
      int remain = target % sum;
      if (remain == 0) {
        return n * times;
      }

      unordered_map<int,int> mp;
      mp[0] = -1;
      int i = 0, j = 0;
      long long preSum = 0;
      int res = INT_MAX;
      while (i < n * 2) {
        preSum += nums[i % n];
        if (mp.find(preSum - remain) != mp.end()) {
          res = min(res, i - mp[preSum - remain]);
        }
        mp[preSum] = i;
        i++;
      }

      return res == INT_MAX ? -1 : times * n + res;
    }
};

/*

[1,2,3,4,5,1,2,3,4,5]


*/