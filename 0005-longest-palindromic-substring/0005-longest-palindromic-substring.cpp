class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.length();
      string t = "#";
      for (int i = 0; i < n; ++i) {
        t += s[i];
        t += '#';
      }
      int m = t.length();
      int maxCenter = -1;
      int maxRight = -1;
      vector<int> P(m);
      for (int i = 0; i < m; ++i) {
        int r = 0;
        if (i < maxRight) {
          int j = maxCenter * 2 - i;
          r = min(P[j], maxRight - i);
          while (i - r >= 0 && i + r < m && t[i - r] == t[i + r]) {
            r++;
          }
        } else {
          r = 0;
          while (i - r >= 0 && i + r < m && t[i - r] == t[i + r]) {
            r++;
          }
        }
        P[i] = r - 1;
        if (i + P[i] > maxRight) {
          maxCenter = i;
          maxRight = i + P[i];
        }
      }
      int center = -1;
      int maxLen = -1;
      for (int i = 0; i < m; ++i) {
        if (P[i] > maxLen) {
          center = i;
          maxLen = P[i];
        }
      }

      return s.substr(center/2 - maxLen/2 , maxLen);
    }
};