class Solution {
public:
    // bottom-up
    // int integerBreak(int n) {
    //   if(n <= 3) return n-1; 
    //   vector<int> dp(n+1,0);
    //   dp[1] = 1;
    //   dp[2] = 2;
    //   dp[3] = 3;
    //   for(int i = 4; i <= n; ++i) {
    //     for(int j = 1; j <= i/2; ++j) {
    //       dp[i] = max(dp[i], dp[i-j]*j);
    //     }
    //   }
    //   return dp[n];
    // }


    //top-down
    int integerBreak(int n) {
      if(n<=3) return n-1;
      memo.resize(n+1, 0);
      return dp(n);
    }

    int dp(int n) {
      if(n <= 3) return n;
      if(memo[n] != 0) return memo[n];

      int ans = 0;
      for(int i = 2; i <= n/2; ++i) {
        ans = max(ans, dp(n-i)*i);
      }
      memo[n] = ans;
      return memo[n];
    }
    vector<int> memo;
};