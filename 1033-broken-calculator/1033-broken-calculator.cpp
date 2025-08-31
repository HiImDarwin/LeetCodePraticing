class Solution {

public:
    int brokenCalc(int startValue, int target) {
      if (target <= startValue) return startValue - target;
      if (target%2 == 1)
        return brokenCalc(startValue, target+1) + 1;
      else 
        return brokenCalc(startValue, target/2) + 1;
    }
};


/*
if startValue < target
if (i%2 == 1)
  dp[i] = min(dp[i/2], dp[i+1] + 1);
else 
  dp[i] = dp[i/2] + 1

definited not DFS

if startValue > target


*/