class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
      int n = nums.size();
      int M = 1e9+7;
      nums.insert(nums.begin(),0);  
      vector<long long> preSum(n+1);
      vector<int> nextSmaller(n+1), preSmaller(n+1);

      preSum[0] = 0;
      for(int i = 1; i <= n; ++i) {
        preSum[i] = preSum[i-1] + nums[i];
      }

      stack<int> preSt;
      for(int i = 1; i <= n; ++i) {
        while(!preSt.empty() && nums[i] <= nums[preSt.top()]) {
          preSt.pop();
        }
        preSmaller[i] = preSt.empty() ? 0 : preSt.top();
        preSt.push(i);
      }

      stack<int> nextSt;
      for(int i = n; i > 0; --i) {
        while(!nextSt.empty() && nums[i] <= nums[nextSt.top()]) {
          nextSt.pop();
        }
        nextSmaller[i] = nextSt.empty() ? n+1 : nextSt.top();
        nextSt.push(i);
      }

      long long res = 0;
      for(int i = 1; i <= n; ++i) {
        res = max(res,(preSum[nextSmaller[i]-1] - preSum[preSmaller[i]]) *nums[i]);
      }
      return res%M;
    }
};


/*
3 4 5 6 12 7 8 9 1 2 8 7 10
find 
i: left smaller index  
j: right smaller index

[i+1,j-1] num[x] is smallest 

use prefix sum preSum[j-1] - preSum[i] * num [x]


*/