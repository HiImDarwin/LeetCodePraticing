class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
      int n = nums.size();
      nums.insert(nums.begin(),0);

      long M = 1e9 + 7;

      vector<int> dp(n+1);
      vector<int> presum(n+1);
      dp[0] = 1;
      presum[0] = 1;

      deque<int> dq1;  // maximum in slinding window
      deque<int> dq2;  // minimum in sliding window
      int L = 1;
      for(int i = 1; i <= n; ++i) {
        // update queue
        while(!dq1.empty() && nums[dq1.back()] < nums[i]) {
          dq1.pop_back();
        }
        dq1.push_back(i);
        while(!dq2.empty() && nums[dq2.back()] > nums[i]) {
          dq2.pop_back();
        }
        dq2.push_back(i);
        //find L
        while(L < i && nums[dq1.front()] - nums[dq2.front()] > k) {
          if(dq1.front() == L) dq1.pop_front();
          if(dq2.front() == L) dq2.pop_front();
          L++;
        }

        dp[i] = presum[i-1] - (L >= 2 ? presum[L-2] : 0);
        dp[i] = (dp[i] + M)% M;
        presum[i] = presum[i-1]+ dp[i];
        presum[i] = (presum[i] + M) % M; 

      }
      return dp[n];
    }
};


/*
1. How to calculate 
for each i, we can find a farest left element at L can make it a segment
when we use L~i segment we got [1....L-1] + [L~1] = dp[L-1]
dp[i] = dp[L-1]+ dp[L] + dp[L+1] + .... + dp[i-1];

2. How to find L 
Each segment can view as sliding window
The difference of maximum and minimum value in window < k
if the window go right and didn't meet bigger or smaller than the window grow > monotonic stack

maximum deque  m
minimum deque  n
if m-n > k then popfront to find second max or second min;
if m-n < k then i ~ min(index(m), index(n)) is the window;


For speedup
it's a accumulate of array -> prefix sum

Technic in this 
DP
monotonic stack
prefix sum
sliding window
*/