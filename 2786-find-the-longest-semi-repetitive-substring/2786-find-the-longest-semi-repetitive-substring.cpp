class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
      int left = 0, right = 1;
      int last_pos = 0;
      int res = 1;
      while (right < s.length()) {
        if (s[right] == s[right - 1]) {
          left = last_pos;
          last_pos = right;
        }
        res = max(res, right - left + 1);
        right++;
      }

      return res;
    }
};

/*
find duplicate for right
s[right] == s[right - 1];

*/