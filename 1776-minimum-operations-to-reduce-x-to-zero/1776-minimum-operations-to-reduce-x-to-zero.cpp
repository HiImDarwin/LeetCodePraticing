class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int n = nums.size(); 
      unordered_map<int,int> forward,backward;
      forward[0] = -1;
      backward[0] = n;
      int forwardSum = 0;
      int backwardSum = 0;

      for(int i = 0 ,j = n-1; i < n; ++i) {
        forwardSum  += nums[i];
        backwardSum += nums[j-i];
        forward[forwardSum] = i;
        backward[backwardSum] = j-i;
      }
      if(forwardSum < x) return -1;
      int res = INT_MAX;
      forwardSum = 0;
      backwardSum = 0;
      if(backward.find(x-forwardSum) != backward.end())
        res = min(res,(n - backward[x-forwardSum]));
      if(forward.find(x-backwardSum) != forward.end())
        res = min(res,(forward[x-backwardSum] + 1));
      for(int i = 0,j = n-1; i < n; ++i) {
        forwardSum  += nums[i];
        backwardSum +  nums[j-i];
        if(backward.find(x-forwardSum) != backward.end()) {
          res = min(res,(i + 1) + (n - backward[x-forwardSum]));
        }
        if(forward.find(x-backwardSum) != forward.end()) {
          res = min(res,(forward[x-backwardSum] + 1) + (n - (j-i)));
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





