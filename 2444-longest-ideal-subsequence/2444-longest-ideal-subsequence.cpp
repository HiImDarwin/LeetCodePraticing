class Solution {
public:
    int longestIdealString(string s, int k) {
      int n = s.length();
      vector<int> best(26, 0); 
      int res = 0;

      for (char c : s) {
        int idx = c - 'a';
        int cur = 1;
        for (int i = max(idx - k, 0); i <= min(idx + k,25); i++) {
          cur = max(cur, best[i] + 1);
        }
        best[idx] = max(cur, best[idx]);
        res = max(res, best[idx]);
      }
      return res;
    }
};

/*

LIS


dp[char][i] = dp[char-1][i-1] - dp[char-1][j] + dp[char][j]

s: lowercase letters 
  find subsequence t
k: threhold of alphabet order

*/