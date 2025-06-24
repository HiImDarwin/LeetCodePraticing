class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int n = s.length();
      if(n == 0) return 0;
      vector<vector<int>> dp(n+1, vector<int> (n,0));

      for(int i = 0; i < n; ++ i) {
        dp[1][i] = 1;
      }
      for (int i = 1; i < n ; ++i) {
        for (int j = 0; j < n - i; ++j) {
          dp[i+1][j] = s[j] == s[j+i] ? dp[i-1][j+1] + 2 : max(dp[i][j], dp[i][j+1]);
        }
      }
      return dp[n][0]; 
    }
};