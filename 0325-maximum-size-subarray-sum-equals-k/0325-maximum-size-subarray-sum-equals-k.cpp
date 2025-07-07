class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<long,int> mp;
      mp[0] = -1;
      long preSum = 0;
      int res = 0;

      for(int i = 0; i < n; ++i) {
        preSum += nums[i];

        if(mp.count(preSum - k)) {
          res = max(res, i - mp[preSum - k]);
        }

        if(!mp.count(preSum)) {
          mp[preSum] = i;
        }
      }
      return res;
    }
};



/*
prefix sum


unordered_map
what if there are two same value







*/