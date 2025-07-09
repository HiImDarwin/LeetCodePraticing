class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
      int n  = nums.size();
      int target = 0;
      long long total = 0;
      for(int &num : nums) {
        total += num;
      }
      target = total%p;
      if(target == 0) return 0;

      unordered_map<int,int> mp;
      mp[0] = -1;

      int pefixSum = 0;
      int res = INT_MAX;
      for(int i = 0; i < n; ++i) {
        pefixSum = (pefixSum+nums[i])%p;
        int rr = ((pefixSum + p - target) % p);

        if(mp.find(rr)!= mp.end()) {
          res = min(res,i-mp[rr]);
        }
        mp[pefixSum] = i;
      }
      return res >= n ? -1: res;
    }

};

/*
all element > 0
remove smalles subarray that subarry sum = accumulate(nums)%p

so we want to know every subarray sum up less than p
use sliding window
|---------------|
i sum up < p    j


1 2 3 1 3 2 4 6   p = 8
[1]
[1 2] [2]
[1 2 3]   [2 3]  [3]
[1 2 3 1]  [2 3 1] [3 1] [1] 

store the sumup,{i,j}

cornor case

[          ] add up more than p but %p is perticular number


*/