class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
      int n = nums.size();
      unordered_map<int,int> mp;
      mp[0] = 1;
      int preSum = 0;
      long res = 0;
      for(int i = 0; i < n; ++i) {
        preSum ^= nums[i];
        if(mp.find(preSum) != mp.end()) {
          res += mp[preSum];
          mp[preSum]++;
        } else {
          mp[preSum] = 1;
        }
      }
      return res;
    }
};


/*
nums[i] & num[j]  if the bit is 1 can be choose as k 
nums[i] and nums[k] - 2^k
so if a sub array can do multi time XOR and all become zero
it is a beautiful subarray

*/

