class Solution {
public:
    int maxProduct(string s) {
      int n = s.size();
      int all = (1 << n) - 1;
      int res = 0;
      for (int subset = 1; subset < all; subset++) {
        res = max(res, longestPalindrome(s, all - subset) * longestPalindrome(s,subset));
      }
      return res;
    }
    int longestPalindrome(string& s, int state) {
      string t;
      for (int i = 0; i < s.size(); i++) {
        if ((state >> i) & 1) {
          t += s[s.size() - 1 - i];
        }
      }

      int n = t.size();
      vector<vector<int>> dp(n, vector<int>(n));
      for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
      }
      for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
          int j = i + len - 1;
          if (t[i] == t[j]) {
            dp[i][j] = dp[i+1][j-1] + 2;
          } else {
            dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
          }
        }
      }

      return dp[0][n-1];
    }
};

/*

LIS longest Incresing Subsequence (X)
LIS longest palindrone Subsequence
manacher palindrone substring
prefix Map

1. how to find all palindrone Subsequence ?
  prefix Map (n^2)
  for each index give vector<int> bitmask for it
  list all possiable 
  dp[i][j]

2. how to solve disjoint ?
  only length 12
  bitmask for picking the index

  ---XX--X-XX-
  -Y----YY----
*/