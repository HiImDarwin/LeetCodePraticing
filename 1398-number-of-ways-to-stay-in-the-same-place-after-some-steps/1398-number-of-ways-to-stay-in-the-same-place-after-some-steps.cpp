class Solution 
{
  public:
    int numWays(int steps, int arrLen) {
      int mod = 1e9 + 7;
      int n = min(steps, arrLen-1);
      vector<int> dp(n+1, 0), tmp(n+1, 0);
      dp[0] = 1;

      for(int i = 1; i <= steps; i++) {
        for(int j = 0; j <= n; j++) {
          int prev = j - 1 >= 0 ? dp[j-1] : 0;
          int curr = dp[j];
          int next = j + 1 <= n ? dp[j + 1] : 0;
          tmp[j] = ((long long)prev + curr + next)%mod;
        }
        swap(dp, tmp);
      }
      return dp[0];
    }
};

/*
for each step you can stay have three
1 2 3 4 5 6 7
1
1 1
2 2 1
4 5 3
9 12 9 3

dp = dp[i-1] + dp[i] + dp[i+1];

*/


 