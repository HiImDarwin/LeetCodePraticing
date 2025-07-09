class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int n = nums.size(); 
      unordered_map<int,int> backward;
      backward[0] = n;
      int preSum = 0;

      for(int i = n-1 ; i >= 0; --i) {
        preSum += nums[i];
        backward[preSum] = i;
      }
      if(preSum < x) return -1;

      int res = INT_MAX;
      if(backward.find(x)!= backward.end())
        res = min(res,n-backward[x]);     
        preSum = 0;
      for(int i = 0; i < n; ++i) {
        preSum += nums[i];
        if(backward.find(x-preSum) != backward.end()) {
          res = min(res,(n-backward[x-preSum]) + i + 1);
        }
      }
      return res == INT_MAX ? -1 : res;
    }
};

/*
xxxx|xxxxxx|xxx


question
1. nums val range
2. nums length
3.`

*/





