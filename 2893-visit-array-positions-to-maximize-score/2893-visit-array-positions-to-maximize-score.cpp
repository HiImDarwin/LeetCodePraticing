class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
      int n = nums.size();
      long long evenMax = LLONG_MIN/2, oddMax = LLONG_MIN/2;
      if(nums[0] %2 == 0) {
        evenMax = nums[0];
      } else {
        oddMax = nums[0];
      }

      for (int i = 1; i < n; i++) {
        long long curr;
        if(nums[i] % 2 == 0) {
          curr = max(evenMax + nums[i] , oddMax + nums[i] - x);
          evenMax = max(curr, evenMax);
        } else {
          curr = max(oddMax + nums[i], evenMax + nums[i] - x);
          oddMax = max(oddMax, curr);
        }
      }
      
      return max(evenMax, oddMax);
    }
};


/*

dp[i][0] dp[i-1][1] +  , dp[i-2][1] + nums[i]
dp[i][1] 
the maximum score from 0 to index i  with i and without last is even/odd



*/