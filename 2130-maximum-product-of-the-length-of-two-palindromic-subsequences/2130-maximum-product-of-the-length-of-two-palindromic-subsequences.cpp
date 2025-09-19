class Solution {
public:
    // int maxProduct(string s) {
    //   int n = s.size();
    //   int all = (1 << n) - 1;
    //   int res = 0;
    //   for (int subset = 1; subset < all; subset++) {
    //     res = max(res, longestPalindrome(s, all - subset) * longestPalindrome(s,subset));
    //   }
    //   return res;
    // }
    // int longestPalindrome(string& s, int state) {
    //   string t;
    //   for (int i = 0; i < s.size(); i++) {
    //     if ((state >> i) & 1) {
    //       t += s[s.size() - 1 - i];
    //     }
    //   }

    //   int n = t.size();
    //   vector<vector<int>> dp(n, vector<int>(n));
    //   for (int i = 0; i < n; i++) {
    //     dp[i][i] = 1;
    //   }
    //   for (int len = 2; len <= n; len++) {
    //     for (int i = 0; i + len - 1 < n; i++) {
    //       int j = i + len - 1;
    //       if (t[i] == t[j]) {
    //         dp[i][j] = dp[i+1][j-1] + 2;
    //       } else {
    //         dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
    //       }
    //     }
    //   }

    //   return dp[0][n-1];
    // }
    int maxProduct(string s) {
      int n = s.length();
      int all = (1 << n) - 1;
      vector<int> lp(1 << n, 0);
      // initialize
      for (int i = 0; i < n; i++) {
        lp[1 << i] = 1;
      }
      int res = 1;
      for (int state = 1; state <= all; state++) {
        if(__builtin_popcount(state) <= 1) {
          continue;
        } 
        int leftIdx = 31 - __builtin_clz(state);
        int rightIdx = __builtin_ctz(state);
        if (s[leftIdx] == s[rightIdx]) {
          int submask = state;
          submask ^= (1 << leftIdx);
          submask ^= (1 << rightIdx);
          lp[state] = lp[submask] + 2;
        } else {
          lp[state] = max(lp[state ^ (1 << leftIdx)], lp[state ^ (1 << rightIdx)]);
        }

        res = max(res, lp[state] * lp[all & (~state)]);
      }
      return res;
    }
};

/*
暴力枚舉
1. 切成兩個subsequence
2. 讓所有 subsequence 計算 LPS




*/