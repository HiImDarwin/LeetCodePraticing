class Solution {
public:
    int maxPalindromes(string s, int k) {
      int n = s.length();
      s = '#' + s;
      vector<int> dp(n+1,0); 
      vector<vector<bool>> dp2(n+1,vector<bool>(n+1,false));
      
      for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        for (int j = i; j >= 1; j--) {
          if (s[i] == s[j] && j + 1 > i - 1) {
            dp2[i][j] = true;
          } else if (s[i] == s[j] && j + 1 <= i - 1) {
            dp2[i][j] = dp2[i - 1][j + 1];
          } else {
            dp2[i][j] = false;
          }

          if (dp2[i][j] && i - j + 1 >= k) {
            dp[i] = max(dp[i], dp[j - 1] + 1);
          } 
        }
      }
      return dp[n];
    }
};